/**
 * @file voltage_sensor.hpp
 *
 * @author Edem Khadiev
 * Contact: khadiev.edem@gmail.com
 */
#pragma once

#include <unordered_map>
#include <vector>

#include "sensor.hpp"
#include "../measurement_result.hpp"

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
  voltage_sensor() : voltage_sensors{} { };

  voltage_sensor(std::initializer_list<std::pair<sensor_name, measurement_result>>& list);

  voltage_sensor(std::vector<std::pair<sensor_name, measurement_result>>& list);

  ~voltage_sensor() final override;

  void measure() final override;

  static constexpr inline const char* get_base_sensor_name() { return base_sensor_name; }

  void add_sensor(const sensor_name& name, const measurement_result& meas) final override;

  void add_sensor(const sensor_name& name, const std::string& sensor_addr) final override;

private:
  std::unordered_map<sensor_name, measurement_result> voltage_sensors;
  
  static constexpr const char* base_sensor_name { "VOL" };
};

} //namespace eekhdv
