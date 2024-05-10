#include "sensors/sensor_factory.hpp"
#include "sensor_impl.hpp"


using namespace eekhdv;

std::unique_ptr<sensor> make_sensor(sensor_configuration& cfg)
{
    return std::make_unique<sensor_impl>(cfg);
}