/**
 * @file temperature_sensor.cpp
 *
 * @author Edem Khadiev
 * Contact: khadiev.edem@gmail.com
 */
#include <iostream>

#include "sensors/temperature_sensor.hpp"


using namespace eekhdv;


void temperature_sensor::measure()
{
    for (auto & sensor_ : sensors_)
    {
      uint8_t rx_buf[8];
      if (i2c_bus.read(sensor_, 8, rx_buf) == 0)
      {
        sensor_.set_last_meas(i2c_comm::bytes_to_int64(rx_buf));
      }
      else
      {
        std::cout << "Cannot measure " << sensor_.get_sensor_name() << '\n';
      }
    }
}

void temperature_sensor::add_sensor(const sensor_type& sensor)
{
  sensors_.push_back(sensor);
}
