/**
 * @file power_sensor.hpp
 *
 * @author Edem Khadiev
 * Contact: khadiev.edem@gmail.com
 */
#pragma once

#include <unordered_map>
#include <vector>

#include "../measurement_result.hpp"
#include "sensor.hpp"


namespace eekhdv
{

/*
 *
 *
 *
**/
class power_sensor final : public sensor
{
public:
  /// @brief 
  /// @param list
  power_sensor() : power_sensors{} { };

  power_sensor(std::initializer_list<std::pair<sensor_name, measurement_result>>& list);

  power_sensor(std::vector<std::pair<sensor_name, measurement_result>>& list);

  ~power_sensor() final override;

  void measure() final override;

  static constexpr inline const char* get_base_sensor_name() { return base_sensor_name; }

  void add_sensor(const sensor_name& name, const measurement_result& meas) final override;

  void add_sensor(const sensor_name& name, const std::string& sensor_addr) final override;

private:
  std::unordered_map<sensor_name, measurement_result> power_sensors;
  
  static constexpr const char* base_sensor_name { "POW" };
};

} // namespace eekhdv
