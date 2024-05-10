#pragma once

#include <memory>

#include "sensor.hpp"
#include "sensor_config.hpp"

namespace eekhdv
{
    /// @brief return ptr to sensor instance
    std::unique_ptr<sensor> make_sensor(sensor_configuration& cfg);
}
