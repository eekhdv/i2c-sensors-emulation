/**
 * @file temperature_sensor.cpp
 *
 * @author Edem Khadiev
 * Contact: khadiev.edem@gmail.com
 */
#include "sensors/temperature_sensor.hpp"


using namespace eekhdv;


temperature_sensor::temperature_sensor(std::initializer_list<std::pair<sensor_name, measurement_result>>& list)
{
  for (const auto & [key, value] : list)
  {
    temperature_sensors[key] = value;
  }
}

temperature_sensor::~temperature_sensor()
{
  // TODO
}

void temperature_sensor::measure()
{

}

void temperature_sensor::add_sensor(const sensor_name& name, const measurement_result& meas)
{
  temperature_sensors[name] = meas;
}

void temperature_sensor::add_sensor(const sensor_name& name, const std::string& sensor_addr)
{
  measurement_result res{sensor_addr};
  add_sensor(name, res);
}
