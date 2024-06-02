/**
 * @file sensor_impl.hpp
 *
 * @author Edem Khadiev
 * Contact: khadiev.edem@gmail.com
 */
#pragma once

#include <array>
#include <memory>

#include "sensors/sensor_config.hpp"
#include "sensors/sensor.hpp"

namespace eekhdv
{

/*
 *
**/
class sensor_impl final : public sensor
{
public:
    /// @brief 
    /// @param sensors 
    sensor_impl(std::array<std::unique_ptr<sensor>, static_cast<std::size_t>(MEASUREMENTS::MAX_NUM)>& sensors) : sensors_{ std::move(sensors) }
    { }

    /// @brief 
    /// @param cfg 
    /// @param temperature_bus 
    /// @param voltage_bus 
    /// @param power_bus 
    /// @param current_bus 
    sensor_impl(const sensor_configuration& cfg);

    void measure() final override;
    
    void add_sensor(const sensor_type&) override;

private:
    std::array<std::unique_ptr<sensor>, static_cast<std::size_t>(MEASUREMENTS::MAX_NUM)> sensors_; ///<
};

} // namespace eekhdv
