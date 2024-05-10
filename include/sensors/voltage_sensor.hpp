#pragma once

#include <unordered_map>

#include "sensor.hpp"
#include "measurement_result.hpp"

namespace eekhdv
{

/*
 *
**/
class voltage_sensor final : public sensor
{
public:
  /// @brief
  /// @param list 
  voltage_sensor(std::initializer_list<std::pair<sensor_name, measurement_result>>& list);

  ~voltage_sensor() final override;

  void measure() final override;

private:
  std::unordered_map<sensor_name, measurement_result> voltage_sensors;
  
};

} //namespace eekhdv
