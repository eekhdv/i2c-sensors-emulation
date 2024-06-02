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

    /// @brief Writing data to the specified i2c device
    /// @param sensor - specified sensor for writing from the buffer
    /// @param buf_size - size of the tx_buffer
    /// @param tx_buffer - buffer to write data from
    /// @return 
    int write(const sensor_type& sensor, uint32_t buf_size, uint8_t* tx_buffer);
    
    /// @brief Reading data from sensor to the given buffer
    /// @param sensor - specified sensor to read data from
    /// @param buf_size  - size of the rx_buffer
    /// @param rx_buffer - write data to this buffer
    /// @return 
    int read(const sensor_type& sensor, uint32_t buf_size, uint8_t* rx_buffer);

    /// @brief convert 8 byte array to int64_t
    /// @param arr - array of 8 bytes
    /// @return converted 64-bit number
    static int64_t bytes_to_int64(uint8_t arr[8]);

private:
    static constexpr uint32_t MAX_BUFFER_SIZE = 10;

    int bus_fd;
};
    
} // namespace eekhdv
