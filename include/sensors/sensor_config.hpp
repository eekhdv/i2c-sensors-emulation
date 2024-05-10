#pragma once

#include <string>
#include <utility>
#include <vector>

namespace eekhdv
{
    
struct sensor_configuration
{
    std::vector<std::pair<std::string, std::string>> sensor_list;
};

} // namespace eekhdv