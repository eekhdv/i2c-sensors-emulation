/**
 * @file current_sensor.cpp
 *
 * @author Edem Khadiev
 * Contact: khadiev.edem@gmail.com
 */
#include "sensors/current_sensor.hpp"


using namespace eekhdv;


current_sensor::current_sensor(std::initializer_list<std::pair<sensor_name, measurement_result>>& list)
{
    for (const auto & [key, value] : list)
    {
        current_sensors[key] = value;
    }
}

current_sensor::~current_sensor()
{
    // TODO
}

void current_sensor::measure()
{
  
}
  
void current_sensor::add_sensor(const sensor_name& name, const measurement_result& meas)
{
  current_sensors[name] = meas;
}

void current_sensor::add_sensor(const sensor_name& name, const std::string& sensor_addr)
{
  measurement_result res{sensor_addr};
  add_sensor(name, res);
}
