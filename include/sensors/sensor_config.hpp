/**
 * @file sensor_config.hpp
 *
 * @author Edem Khadiev
 * Contact: khadiev.edem@gmail.com
 */
#pragma once

#include <string>
#include <utility>
#include <vector>

namespace eekhdv
{
    
/*
 *
**/
struct sensor_configuration
{
    std::vector<std::pair<std::string, uint8_t>> sensor_list;
    uint8_t temperature_bus;
    uint8_t voltage_bus;
    uint8_t power_bus;
    uint8_t current_bus;
};

} // namespace eekhdv
