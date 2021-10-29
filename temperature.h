#pragma once
#include <string>

namespace mmotd::temperature {

double GetCpuTemperature();
double GetGpuTemperature();

double ConvertCelciusToFahrenheit(double celcius_temperature) noexcept;

enum class Scale { Unknown, Low, Medium, High };

Scale GetScaleFromTemperature(double celcius_temperature) noexcept;

std::string GetTemperatureIcon(double celcius_temperature) noexcept;
std::string GetTemperatureIcon(Scale scale) noexcept;

}  // namespace mmotd::temperature
