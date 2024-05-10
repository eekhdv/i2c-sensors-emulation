#pragma once

#include <unordered_map>

#include "sensor.hpp"
#include "measurement_result.hpp"


namespace eekhdv
{

class temperature_sensor final : public sensor
{
public:
  temperature_sensor() = delete;
  temperature_sensor(std::initializer_list<std::pair<sensor_name, measurement_result>>& list);

  ~temperature_sensor() final override;

  void measure() final override;

private:
  std::unordered_map<sensor_name, measurement_result> temperature_sensors;
};

} // namespace eekhdv
