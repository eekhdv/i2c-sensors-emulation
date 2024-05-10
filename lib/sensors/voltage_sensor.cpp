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

