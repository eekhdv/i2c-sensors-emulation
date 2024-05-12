/**
 * @file sensor_factory.cpp
 *
 * @author Edem Khadiev
 * Contact: khadiev.edem@gmail.com
 */
#include "sensors/sensor_factory.hpp"
#include "sensor_impl.hpp"


using namespace eekhdv;

std::unique_ptr<sensor> sensor_factory::make_sensor(const sensor_configuration& cfg)
{
    return std::make_unique<sensor_impl>(cfg);
}
