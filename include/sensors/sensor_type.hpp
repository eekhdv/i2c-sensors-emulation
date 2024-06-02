/**
 * @file measurement_result.hpp
 *
 * @author Edem Khadiev
 * Contact: khadiev.edem@gmail.com
 */
#pragma once

#include <cstdint>
#include <string>
#include <vector>


namespace eekhdv
{

/// @brief 
enum class MEASUREMENTS : std::size_t
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
class measurement_type
{
public:

    measurement_type(int64_t res_ = 0) : res{res_}{}

    int64_t get_result() const { return res; }

    void set_result(int64_t res_) { res = res_; }

private:
    int64_t res; ///< measurement result
};
    
class sensor_type
{
public:
  sensor_type() = delete;

  sensor_type(const std::string& name, uint8_t dev_addr_): meas_history{},
                                                           last_meas{},
                                                           sensor_name{name},
                                                           dev_addr{dev_addr_}
  { }

public:
  const measurement_type& get_last_meas() const & { return last_meas; }

  const std::string& get_sensor_name() const & { return sensor_name; }

  uint8_t get_sensor_addr() const { return dev_addr; }
  
  /// @brief update last measurement
  /// @param result - new measurement value
  void set_last_meas(int64_t result)
  {
    meas_history.push_back(last_meas);
    last_meas.set_result(result);
  }
  
private:
  std::vector<measurement_type> meas_history;
  measurement_type              last_meas;

  std::string                   sensor_name;
  uint8_t                       dev_addr;
};

}
