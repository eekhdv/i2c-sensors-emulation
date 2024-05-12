/**
 * @file voltage_sensor.cpp
 *
 * @author Edem Khadiev
 * Contact: khadiev.edem@gmail.com
 */
#include "sensors/voltage_sensor.hpp"


using namespace eekhdv;


voltage_sensor::voltage_sensor(std::initializer_list<std::pair<sensor_name, measurement_result>>& list)
{
    for (const auto & [key, value] : list)
    {
        voltage_sensors[key] = value;
    }
}

voltage_sensor::~voltage_sensor()
{
    // TODO
}

void voltage_sensor::measure()
{
  
}

void voltage_sensor::add_sensor(const sensor_name& name, const measurement_result& meas)
{
  voltage_sensors[name] = meas;
}

void voltage_sensor::add_sensor(const sensor_name& name, const std::string& sensor_addr)
{
  measurement_result res{sensor_addr};
  add_sensor(name, res);
}
