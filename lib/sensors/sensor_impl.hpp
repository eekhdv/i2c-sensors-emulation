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
    sensor_impl(std::array<std::unique_ptr<sensor>, static_cast<std::size_t>(measurement::MAX_NUM)> sensors) : sensors{ std::move(sensors) }
    { }

    /// @brief 
    /// @param cfg
    sensor_impl(const sensor_configuration& cfg);

    ~sensor_impl() final override;
    
    void measure() final override;
    
    void add_sensor(const sensor_name&, const measurement_result&) override;

    void add_sensor(const sensor_name&, const std::string&) override;

private:
    std::array<std::unique_ptr<sensor>, static_cast<std::size_t>(measurement::MAX_NUM)> sensors; ///<
};

} // namespace eekhdv
