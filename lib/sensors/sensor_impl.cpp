/**
 * @file sensor_impl.cpp
 *
 * @author Edem Khadiev
 * Contact: khadiev.edem@gmail.com
 */
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "sensor_impl.hpp"
#include "sensors/current_sensor.hpp"
#include "sensors/power_sensor.hpp"
#include "sensors/temperature_sensor.hpp"
#include "sensors/voltage_sensor.hpp"

using namespace eekhdv;


sensor_impl::sensor_impl(const sensor_configuration& cfg)
{
  std::unique_ptr<temperature_sensor> tmp_sensor {new temperature_sensor{cfg.temperature_bus}};
  std::unique_ptr<voltage_sensor>     vol_sensor {new voltage_sensor{cfg.voltage_bus}};
  std::unique_ptr<power_sensor>       pow_sensor {new power_sensor{cfg.power_bus}};
  std::unique_ptr<current_sensor>     cur_sensor {new current_sensor{cfg.current_bus}};
  

  for (const auto & [name, addr] : cfg.sensor_list)
  {
    if (name.find(temperature_sensor::get_base_sensor_name()) != std::string::npos)
    {
      tmp_sensor->add_sensor({name, addr});
    }
    else if (name.find(voltage_sensor::get_base_sensor_name()) != std::string::npos)
    {
      vol_sensor->add_sensor({name, addr});
    }
    else if (name.find(power_sensor::get_base_sensor_name()) != std::string::npos)
    {
      pow_sensor->add_sensor({name, addr});
    }
    else if (name.find(current_sensor::get_base_sensor_name()) != std::string::npos)
    {
      cur_sensor->add_sensor({name, addr});
    }
  }

  sensors_.at(static_cast<size_t>(MEASUREMENTS::TEMPERATURE)) = std::move(tmp_sensor);
  sensors_.at(static_cast<size_t>(MEASUREMENTS::VOLTAGE))     = std::move(vol_sensor);
  sensors_.at(static_cast<size_t>(MEASUREMENTS::POWER))       = std::move(pow_sensor);
  sensors_.at(static_cast<size_t>(MEASUREMENTS::CURRENT))     = std::move(cur_sensor);
}

void sensor_impl::measure()
{
    for (auto & sensors_arr : sensors_)
    {
      sensors_arr->measure();
    }
}

void sensor_impl::add_sensor(const sensor_type& sensor_)
{
  if (sensor_.get_sensor_name().find(temperature_sensor::get_base_sensor_name()) != std::string::npos)
  {
    sensors_.at(static_cast<size_t>(MEASUREMENTS::TEMPERATURE))->add_sensor(sensor_);
  }
  else if (sensor_.get_sensor_name().find(voltage_sensor::get_base_sensor_name()) != std::string::npos)
  {
    sensors_.at(static_cast<size_t>(MEASUREMENTS::VOLTAGE))->add_sensor(sensor_);
  }
  else if (sensor_.get_sensor_name().find(power_sensor::get_base_sensor_name()) != std::string::npos)
  {
    sensors_.at(static_cast<size_t>(MEASUREMENTS::POWER))->add_sensor(sensor_);
  }
  else if (sensor_.get_sensor_name().find(current_sensor::get_base_sensor_name()) != std::string::npos)
  {
    sensors_.at(static_cast<size_t>(MEASUREMENTS::CURRENT))->add_sensor(sensor_);
  }
}
