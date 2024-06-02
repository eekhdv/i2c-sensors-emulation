#include "i2c/i2c_comm.hpp"

using namespace eekhdv;

i2c_comm::i2c_comm(int i2c_bus)
{
    std::string bus_addr_str {"/dev/i2c-" + std::to_string(i2c_bus)};
    bus_fd = open(bus_addr_str.c_str(), O_RDWR);
}

int i2c_comm::write(const sensor_type& sensor, uint32_t buf_size, uint8_t* tx_buffer)
{
    if (ioctl(bus_fd, I2C_SLAVE, sensor.get_sensor_addr()) != 0)
    {
        return -1;
    }
    
    if (buf_size > MAX_BUFFER_SIZE)
    {
        return -1;
    }

    union i2c_smbus_data data;

    for (uint16_t i = 1; i <= buf_size; ++i)
    {
      data.block[i] = tx_buffer[i];

    }
    data.block[0] = buf_size;

    struct i2c_smbus_ioctl_data args
    {
      .read_write = I2C_SMBUS_WRITE,
      .command    = 0x01,
      .size       = I2C_SMBUS_I2C_BLOCK_BROKEN,
      .data       = &data,
    };

    return ioctl(bus_fd, I2C_SMBUS, &args);
}

int i2c_comm::read(const sensor_type& sensor, uint32_t buf_size, uint8_t* rx_buffer)
{
    if (ioctl(bus_fd, I2C_SLAVE, 0x09) != 0)
    {
      return -1;
    }

    union i2c_smbus_data data;

    data.block[0] = buf_size;

    struct i2c_smbus_ioctl_data args
    {
        .read_write = I2C_SMBUS_READ,
        .command    = 0x00,
        .size       = I2C_SMBUS_I2C_BLOCK_DATA,
        .data       = &data,
    };

    if (ioctl(bus_fd, I2C_SMBUS, &args) == 0)
    {
      for (uint16_t i = 1; i <= data.block[0]; ++i)
      {
        printf("%d ", data.block[i]);
      }
      return 0;
    }

    return -1;
}        

int64_t i2c_comm::bytes_to_int64(uint8_t arr[8])
{
   uint64_t v = 0;
   v |= arr[0]; v <<= 8;
   v |= arr[1]; v <<= 8;
   v |= arr[2]; v <<= 8;
   v |= arr[3]; v <<= 8;
   v |= arr[4]; v <<= 8;
   v |= arr[5]; v <<= 8;
   v |= arr[6]; v <<= 8;
   v |= arr[7];
   return (int64_t)v;
}