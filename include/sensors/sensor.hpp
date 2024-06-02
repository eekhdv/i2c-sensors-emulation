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
 *
**/
class sensor
{
public:
  virtual ~sensor() = default;

  /// @brief 
  /// @return
  virtual void measure() = 0;

  virtual void add_sensor(const sensor_type&) = 0;

};

} // namespace eekhdv
