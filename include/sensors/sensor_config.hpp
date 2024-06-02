/**
 * @file sensor_config.hpp
 *
 * @author Edem Khadiev
 * Contact: khadiev.edem@gmail.com
 */
#pragma once

#include "sensor_type.hpp"
#include <array>
#include <cstdint>
#include <string>
#include <utility>
#include <vector>

namespace eekhdv
{
    
/*
 * Configuration for factory class
**/
struct sensor_configuration
{
    std::vector<std::pair<std::string, uint8_t>> sensor_list;
    std::array<uint8_t, static_cast<size_t>(eekhdv::MEASUREMENTS::MAX_NUM)> bus_arr;
};

} // namespace eekhdv
