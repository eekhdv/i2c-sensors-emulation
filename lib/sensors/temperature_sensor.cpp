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
}
