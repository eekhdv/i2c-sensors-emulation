/**
 * @file temperature_sensor.hpp
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

class temperature_sensor final : public sensor
{
public:
  /// @brief 
  /// @param
  temperature_sensor() : temperature_sensors{} { }

  temperature_sensor(std::initializer_list<std::pair<sensor_name, measurement_result>>& list);

  temperature_sensor(std::vector<std::pair<sensor_name, measurement_result>>& list);

  ~temperature_sensor() final override;

  void measure() final override;

  static constexpr inline const char* get_base_sensor_name() { return base_sensor_name; }

  void add_sensor(const sensor_name& name, const measurement_result& meas) final override;

  void add_sensor(const sensor_name& name, const std::string& sensor_addr) final override;

private:
  std::unordered_map<sensor_name, measurement_result> temperature_sensors;

  static constexpr const char* base_sensor_name { "TMP" };
};

} // namespace eekhdv
