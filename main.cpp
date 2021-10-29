// vim: awa:sts=4:ts=4:sw=4:et:cin:fdm=manual:tw=120:ft=cpp
#include <algorithm>
#include <cstdlib>
#include <exception>
#include <filesystem>
#include <iostream>
#include <iterator>
#include <string>

#include <fmt/format.h>

#include "temperature.h"

using namespace std;

int main(int argc, const char **argv) {
    (void)argc;
    (void)argv;
    try {
        auto cpu_temp = mmotd::temperature::GetCpuTemperature();
        auto gpu_temp = mmotd::temperature::GetGpuTemperature();
        auto cpu_temp_f = mmotd::temperature::ConvertCelciusToFahrenheit(cpu_temp);
        auto gpu_temp_f = mmotd::temperature::ConvertCelciusToFahrenheit(gpu_temp);
        auto cpu_icon = mmotd::temperature::GetTemperatureIcon(cpu_temp);
        auto gpu_icon = mmotd::temperature::GetTemperatureIcon(gpu_temp);

        fmt::print("cpu temperature: {} {:.3f}°C {:.3f}°F\n", cpu_icon, cpu_temp, cpu_temp_f);
        fmt::print("gpu temperature: {} {:.3f}°C {:.3f}°F\n", gpu_icon, gpu_temp, gpu_temp_f);
    } catch (const std::exception &ex) { cerr << "caught std::exception: " << ex.what() << endl; } catch (...) {
        cerr << "caught unknown exception" << endl;
    }
    return EXIT_SUCCESS;
}
