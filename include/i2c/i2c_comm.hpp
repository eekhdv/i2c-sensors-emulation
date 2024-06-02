/**
 * @file i2c_comm.hpp
 *
 * @author Edem Khadiev
 * Contact: khadiev.edem@gmail.com
 */
#pragma once

#include <linux/i2c.h>
#include <linux/i2c-dev.h>

#include <sys/ioctl.h>

#include <string>
#include <cstdlib>
#include <fcntl.h>
#include <unistd.h>

#include "sensors/sensor_type.hpp"

namespace eekhdv
{
    
class i2c_comm
{
public:
    i2c_comm() = delete;

    /// @brief 
    /// @param i2c_bus 
    i2c_comm(int i2c_bus);
    
    ~i2c_comm() { close(bus_fd); }

    /// @brief 
    /// @param sensor 
    /// @param buf_size 
    /// @param tx_buffer 
    /// @return 
    int write(const sensor_type& sensor, uint32_t buf_size, uint8_t* tx_buffer);
    
    /// @brief 
    /// @param sensor 
    /// @param buf_size 
    /// @param rx_buffer 
    /// @return 
    int read(const sensor_type& sensor, uint32_t buf_size, uint8_t* rx_buffer);

    /// @brief 
    /// @param arr 
    /// @return 
    static int64_t bytes_to_int64(uint8_t arr[8]);

private:
    static constexpr uint32_t MAX_BUFFER_SIZE = 10;

    int bus_fd;
};
    
} // namespace eekhdv