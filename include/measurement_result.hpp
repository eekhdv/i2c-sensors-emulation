/**
 * @file measurement_result.hpp
 *
 * @author Edem Khadiev
 * Contact: khadiev.edem@gmail.com
 */
#pragma once

#include <cstdint>
#include <string>


namespace eekhdv
{
    
using sensor_name = std::string;

/// @brief 
enum class measurement : std::size_t
{
  POWER = 0,
  TEMPERATURE,
  VOLTAGE,
  CURRENT,

  MAX_NUM ///<
};

/*
 *
**/
class measurement_result
{
public:

    measurement_result() : res{ 0 }, dev_addr{} { };

    measurement_result(int64_t res_, const std::string& dev_addr_) : res{res_}, dev_addr{dev_addr_} {}

    measurement_result(const std::string& dev_addr_) : res{0}, dev_addr{dev_addr_} {}

    /// @brief 
    /// @return
    int64_t get_result() const { return res; }

    /// @brief 
    /// @return
    const std::string& get_dev_addr() const & { return dev_addr; }

private:
    int64_t res; ///< 
    std::string dev_addr; ///<
};

}
