/**
 * @file sensor.hpp
 *
 * @author Edem Khadiev
 * Contact: khadiev.edem@gmail.com
 */
#pragma once

#include "sensor_type.hpp"

namespace eekhdv
{

/*
 * Base sensor class
**/
class sensor
{
public:
  virtual ~sensor() = default;

  /// @brief Method for update measurements from sensor
  virtual void measure() = 0;

  /// @brief Add new sensor to the sensor array
  /// @param sensor_type - sensor to be added
  virtual void add_sensor(const sensor_type&) = 0;

};

} // namespace eekhdv
