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
  std::unique_ptr<temperature_sensor> tmp_sensor {new temperature_sensor{}};
  std::unique_ptr<voltage_sensor>     vol_sensor {new voltage_sensor{}};
  std::unique_ptr<power_sensor>       pow_sensor {new power_sensor{}};
  std::unique_ptr<current_sensor>     cur_sensor {new current_sensor{}};
  

  for (const auto & [name, addr] : cfg.sensor_list)
  {
    if (name.find(temperature_sensor::get_base_sensor_name()) != std::string::npos)
    {
      tmp_sensor->add_sensor(name, addr);
    }
    else if (name.find(voltage_sensor::get_base_sensor_name()) != std::string::npos)
    {
      vol_sensor->add_sensor(name, addr);
    }
    else if (name.find(power_sensor::get_base_sensor_name()) != std::string::npos)
    {
      pow_sensor->add_sensor(name, addr);
    }
    else if (name.find(current_sensor::get_base_sensor_name()) != std::string::npos)
    {
      cur_sensor->add_sensor(name, addr);
    }
  }

  sensors.at(static_cast<size_t>(measurement::TEMPERATURE)) = std::move(tmp_sensor);
  sensors.at(static_cast<size_t>(measurement::VOLTAGE))     = std::move(vol_sensor);
  sensors.at(static_cast<size_t>(measurement::POWER))       = std::move(pow_sensor);
  sensors.at(static_cast<size_t>(measurement::CURRENT))     = std::move(cur_sensor);
}

sensor_impl::~sensor_impl()
{
    // TODO:
}

void sensor_impl::measure()
{
    // TODO:
    
}

void sensor_impl::add_sensor(const sensor_name& name, const measurement_result& meas)
{
    if (name.find(temperature_sensor::get_base_sensor_name()) != std::string::npos)
    {
      sensors.at(static_cast<size_t>(measurement::TEMPERATURE))->add_sensor(name, meas);
    }
    else if (name.find(voltage_sensor::get_base_sensor_name()) != std::string::npos)
    {
      sensors.at(static_cast<size_t>(measurement::VOLTAGE))->add_sensor(name, meas);
    }
    else if (name.find(power_sensor::get_base_sensor_name()) != std::string::npos)
    {
      sensors.at(static_cast<size_t>(measurement::POWER))->add_sensor(name, meas);
    }
    else if (name.find(current_sensor::get_base_sensor_name()) != std::string::npos)
    {
      sensors.at(static_cast<size_t>(measurement::CURRENT))->add_sensor(name, meas);
    }
}

void sensor_impl::add_sensor(const sensor_name& name, const std::string& addr)
{
  measurement_result meas{ addr };
  add_sensor(name, meas);
}
