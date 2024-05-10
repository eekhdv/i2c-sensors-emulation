#pragma once

#include <unordered_map>

#include "measurement_result.hpp"
#include "sensor.hpp"

namespace eekhdv
{

/*
 *
 *
 *
**/
class current_sensor final : public sensor
{
public:
  /// @brief 
  /// @param list 
  current_sensor(std::initializer_list<std::pair<sensor_name, measurement_result>>& list);

  ~current_sensor() final override;

  void measure() final override;

private:
  std::unordered_map<sensor_name, measurement_result> current_sensors;
  
};

} // namespace eekhdv
