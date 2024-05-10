/**
 * @file measurement_result.hpp
 *
 * @brief File with measurement_result type
 *
 * @author Edem Khadiev
 * Contact: khadiev.edem@gmail.com
 *
 */

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