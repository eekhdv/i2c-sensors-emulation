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
  
