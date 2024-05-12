/**
 * @file sensor.hpp
 *
 * @author Edem Khadiev
 * Contact: khadiev.edem@gmail.com
 */
#pragma once

#include "../measurement_result.hpp"

namespace eekhdv
{

/*
 *
**/
class sensor
{
public:
  virtual ~sensor() = default;

  /// @brief 
  /// @return
  virtual void measure() = 0;

  virtual void add_sensor(const sensor_name&, const std::string& sensor_addr) = 0;

  virtual void add_sensor(const sensor_name&, const measurement_result&) = 0;

private:
};

} // namespace eekhdv
