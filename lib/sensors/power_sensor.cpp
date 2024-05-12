/**
 * @file power_sensor.cpp
 *
 * @author Edem Khadiev
 * Contact: khadiev.edem@gmail.com
 */
#include "sensors/power_sensor.hpp"


using namespace eekhdv;


power_sensor::power_sensor(std::initializer_list<std::pair<sensor_name, measurement_result>>& list)
{
    for (const auto & [key, value] : list)
    {
        power_sensors[key] = value;
    }
}

power_sensor::~power_sensor()
{
    // TODO
}

void power_sensor::measure()
{
  
}

void power_sensor::add_sensor(const sensor_name& name, const measurement_result& meas)
{
  power_sensors[name] = meas;
}

void power_sensor::add_sensor(const sensor_name& name, const std::string& sensor_addr)
{
  measurement_result res{sensor_addr};
  add_sensor(name, res);
}
