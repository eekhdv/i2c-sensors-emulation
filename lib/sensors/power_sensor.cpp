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
