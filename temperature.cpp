#include <cassert>
#include <cstdio>
#include <optional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include <fmt/format.h>

#include <arpa/inet.h>

#include <IOKit/IOKitLib.h>

#include "temperature.h"

using namespace std;

namespace {

constexpr const int KERNEL_INDEX_SMC = 2;

constexpr const char SMC_CMD_READ_BYTES = 5;
constexpr const char SMC_CMD_READ_INDEX = 8;
constexpr const char SMC_CMD_READ_KEYINFO = 9;

const char DATATYPE_SP78[] = "sp78";

struct SMCKeyData_vers_t {
    char major = 0;
    char minor = 0;
    char build = 0;
    char reserved[1] = {0};
    uint16_t release = 0;
};

struct SMCKeyData_pLimitData_t {
    uint16_t version = 0;
    uint16_t length = 0;
    uint32_t cpuPLimit = 0;
    uint32_t gpuPLimit = 0;
    uint32_t memPLimit = 0;
};

struct SMCKeyData_keyInfo_t {
    uint32_t dataSize = 0;
    uint32_t dataType = 0;
    char dataAttributes = 0;
};

typedef unsigned char SMCBytes_t[32];

struct SMCKeyData_t {
    uint32_t key = 0;
    SMCKeyData_vers_t vers;
    SMCKeyData_pLimitData_t pLimitData;
    SMCKeyData_keyInfo_t keyInfo;
    char result = 0;
    char status = 0;
    char data8 = 0;
    uint32_t data32 = 0;
    SMCBytes_t bytes = {0};
};

typedef char UInt32Char_t[5];

struct SMCVal_t {
    UInt32Char_t key = {0};
    uint32_t dataSize = 0;
    UInt32Char_t dataType = {0};
    SMCBytes_t bytes = {0};
};

uint32_t _strtoul(const char *str, int size, int base) {
    uint32_t total = 0;
    for (int i = 0; i < size; ++i) {
        if (base == 16)
            total += str[i] << (size - 1 - i) * 8;
        else
            total += ((unsigned char)(str[i]) << (size - 1 - i) * 8);
    }
    return total;
}

void _ultostr(char *str, uint32_t val) {
    str[0] = '\0';
    sprintf(str,
            "%c%c%c%c",
            (unsigned int)val >> 24,
            (unsigned int)val >> 16,
            (unsigned int)val >> 8,
            (unsigned int)val);
}

class SystemManagementController {
public:
    SystemManagementController();
    ~SystemManagementController();

    double GetCpuTemperature() const noexcept { return cpu_temperature_; }
    double GetGpuTemperature() const noexcept { return gpu_temperature_; }

    vector<pair<string, double>> ReadAllNamedTemperatures();

    bool ReadCpuTemperature();
    bool ReadGpuTemperature();

private:
    void Open();
    void Close();

    kern_return_t ConnectCall(int index, const SMCKeyData_t *input, SMCKeyData_t *output);
    kern_return_t GetKeyInfo(uint32_t key, SMCKeyData_keyInfo_t *keyInfo);
    size_t GetKeyCount();
    kern_return_t ReadKey(const UInt32Char_t key, SMCVal_t *val);
    double GetSP78Value(const SMCVal_t &val) const;

    io_connect_t connect_ = 0;
    double cpu_temperature_ = 0.0;
    double gpu_temperature_ = 0.0;
};

SystemManagementController::SystemManagementController() {
    static_assert(std::is_same<UInt16, uint16_t>::value, "ensure UInt16 and uint16_t are identical");
    static_assert(std::is_same<SInt16, int16_t>::value, "ensure SInt16 and int16_t are identical");
    static_assert(std::is_same<UInt32, uint32_t>::value, "ensure UInt32 and uint32_t are identical");
    Open();
}

SystemManagementController::~SystemManagementController() {
    Close();
}

void SystemManagementController::Open() {
    mach_port_t master_port;
    IOMasterPort(MACH_PORT_NULL, &master_port);

    CFMutableDictionaryRef matching_dict = IOServiceMatching("AppleSMC");

    io_iterator_t iterator;
    kern_return_t result = IOServiceGetMatchingServices(master_port, matching_dict, &iterator);
    if (result != kIOReturnSuccess) {
        auto error_str = fmt::format("ERROR: IOServiceGetMatchingServices failed: {:08x}", result);
        throw std::runtime_error(error_str);
    }

    io_object_t device = IOIteratorNext(iterator);
    IOObjectRelease(iterator);
    if (device == 0) {
        auto error_str = string{"ERROR: IOIteratorNext failed to return a device"};
        throw std::runtime_error(error_str);
    }

    result = IOServiceOpen(device, mach_task_self(), 0, &connect_);
    IOObjectRelease(device);
    if (result != kIOReturnSuccess) {
        auto error_str = fmt::format("ERROR: IOServiceOpen failed: {:08x}", result);
        throw std::runtime_error(error_str);
    }
}

void SystemManagementController::Close() {
    if (connect_ != 0) {
        IOServiceClose(connect_);
    }
}

kern_return_t SystemManagementController::GetKeyInfo(uint32_t key, SMCKeyData_keyInfo_t *keyInfo) {
    SMCKeyData_t input;
    memset(&input, 0, sizeof(input));
    SMCKeyData_t output;
    memset(&output, 0, sizeof(output));

    input.key = key;
    input.data8 = SMC_CMD_READ_KEYINFO;

    kern_return_t result = ConnectCall(KERNEL_INDEX_SMC, &input, &output);
    if (result == kIOReturnSuccess) {
        *keyInfo = output.keyInfo;
    }
    return result;
}

kern_return_t SystemManagementController::ConnectCall(int index, const SMCKeyData_t *input, SMCKeyData_t *output) {
    assert(connect_ != 0);
    size_t inputSize = sizeof(SMCKeyData_t);
    size_t outputSize = sizeof(SMCKeyData_t);
    return IOConnectCallStructMethod(connect_, index, input, inputSize, output, &outputSize);
}

kern_return_t SystemManagementController::ReadKey(const UInt32Char_t key, SMCVal_t *val) {
    SMCKeyData_t input;
    memset(&input, 0, sizeof(SMCKeyData_t));
    SMCKeyData_t output;
    memset(&output, 0, sizeof(SMCKeyData_t));
    memset(val, 0, sizeof(SMCVal_t));

    input.key = _strtoul(key, 4, 16);
    memcpy(val->key, key, sizeof(UInt32Char_t));

    kern_return_t result = GetKeyInfo(input.key, &output.keyInfo);
    if (result != kIOReturnSuccess) {
        return result;
    }

    val->dataSize = output.keyInfo.dataSize;
    _ultostr(val->dataType, output.keyInfo.dataType);
    input.keyInfo.dataSize = val->dataSize;
    input.data8 = SMC_CMD_READ_BYTES;

    result = ConnectCall(KERNEL_INDEX_SMC, &input, &output);
    if (result != kIOReturnSuccess) {
        return result;
    }

    memcpy(val->bytes, output.bytes, sizeof(output.bytes));

    return kIOReturnSuccess;
}

double SystemManagementController::GetSP78Value(const SMCVal_t &val) const {
    if (strcmp(val.dataType, DATATYPE_SP78) == 0 && val.dataSize == 2) {
        return static_cast<int16_t>(ntohs(*reinterpret_cast<const uint16_t *>(val.bytes))) / 256.0;
    } else {
        return 0.0;
    }
}

size_t SystemManagementController::GetKeyCount() {
    SMCVal_t val;
    UInt32Char_t key{"#KEY"};
    ReadKey(key, &val);
    return _strtoul((char *)val.bytes, val.dataSize, 10);
}

vector<pair<string, double>> SystemManagementController::ReadAllNamedTemperatures() {
    auto temperatures = vector<pair<string, double>>{};
    auto key_count = GetKeyCount();
    for (size_t i = 0; i < key_count; ++i) {
        SMCKeyData_t input;
        memset(&input, 0, sizeof(SMCKeyData_t));
        SMCKeyData_t output;
        memset(&output, 0, sizeof(SMCKeyData_t));
        SMCVal_t val;
        memset(&val, 0, sizeof(SMCVal_t));

        input.data8 = SMC_CMD_READ_INDEX;
        input.data32 = i;

        kern_return_t result = ConnectCall(KERNEL_INDEX_SMC, &input, &output);
        if (result != kIOReturnSuccess) {
            continue;
        }

        UInt32Char_t key;
        _ultostr(key, output.key);
        if (key[0] != 'T') {
            continue;
        }

        result = ReadKey(key, &val);
        if (result != kIOReturnSuccess) {
            continue;
        }
        temperatures.push_back(make_pair(val.key, GetSP78Value(val)));
    }
    return temperatures;
}

bool SystemManagementController::ReadCpuTemperature() {
    static const char *SMC_CPU_TEMP_KEY = "TC0P";
    SMCVal_t val;
    UInt32Char_t key;
    memcpy(key, SMC_CPU_TEMP_KEY, sizeof(UInt32Char_t));
    auto result = ReadKey(key, &val);
    if (result == kIOReturnSuccess) {
        cpu_temperature_ = GetSP78Value(val);
    }
    return true;
}

bool SystemManagementController::ReadGpuTemperature() {
    static const char *SMC_GPU_TEMP_KEY = "TG0P";
    SMCVal_t val;
    UInt32Char_t key;
    memcpy(key, SMC_GPU_TEMP_KEY, sizeof(UInt32Char_t));
    auto result = ReadKey(key, &val);
    if (result == kIOReturnSuccess) {
        gpu_temperature_ = GetSP78Value(val);
    }
    return true;
}

} // namespace

namespace mmotd::temperature {

double GetCpuTemperature() {
    static optional<double> cpu_temperature;
    if (!cpu_temperature) {
        auto smc = SystemManagementController{};
        if (!smc.ReadCpuTemperature()) {
            return 0.0;
        }
        cpu_temperature = smc.GetCpuTemperature();
    }
    return cpu_temperature.value_or(0.0);
}

double GetGpuTemperature() {
    static optional<double> gpu_temperature;
    if (!gpu_temperature) {
        auto smc = SystemManagementController{};
        if (!smc.ReadGpuTemperature()) {
            return 0.0;
        }
        gpu_temperature = smc.GetGpuTemperature();
    }
    return gpu_temperature.value_or(0.0);
}

double ConvertCelciusToFahrenheit(double celcius_temperature) noexcept {
    return (celcius_temperature * (9.0 / 5.0)) + 32.0;
}

Scale GetScaleFromTemperature(double celcius_temperature) noexcept {
    // static constexpr const auto LOW_TEMPERATURE = 65.0f;
    static constexpr const auto MEDIUM_TEMPERATURE = 75.0f;
    static constexpr const auto HIGH_TEMPERATURE = 90.0f;
    if (celcius_temperature < MEDIUM_TEMPERATURE) {
        return Scale::Low;
    } else if (celcius_temperature < HIGH_TEMPERATURE) {
        return Scale::Medium;
    } else {
        return Scale::High;
    }
}

string GetTemperatureIcon(double celcius_temperature) noexcept {
    return GetTemperatureIcon(GetScaleFromTemperature(celcius_temperature));
}

string GetTemperatureIcon(Scale scale) noexcept {
    static const char *THERMOMETER_HALF = "\uE20A";
    static const char *THERMOMETER_FULL = "\uE20B";
    static const char *THERMOMETER_EMPTY = "\uE20C";
    static const char *FIRE_UNKNOWN = "\uF490";
    switch (scale) {
        case Scale::Low:
            return THERMOMETER_EMPTY;
            break;
        case Scale::Medium:
            return THERMOMETER_HALF;
            break;
        case Scale::High:
            return THERMOMETER_FULL;
            break;
        case Scale::Unknown:
        default:
            return FIRE_UNKNOWN;
            break;
    }
}

} // namespace mmotd::temperature
