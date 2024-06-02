/**
 * @file sensor_factory.hpp
 *
 * @author Edem Khadiev
 * Contact: khadiev.edem@gmail.com
 */
#pragma once

#include <memory>

#include "sensor.hpp"
#include "sensor_config.hpp"

namespace eekhdv
{
    class sensor_factory
    {
    public:
        /// @brief return ptr to the sensor instance
        /// @param cfg - configuration for creating instance
        static std::unique_ptr<sensor> make_sensor(const sensor_configuration& cfg);
    };
}
