#include <cstdint>
#include <linux/i2c-dev.h>
#include <i2c/smbus.h>
#include <memory>

#include "sensors/sensor_factory.hpp"


int main (int argc, char *argv[])
{
  eekhdv::sensor_configuration cfg = {
    .sensor_list = {
      {"TMP01",  8},
      {"TMP02",  9},
      {"TMP03", 10},
      {"TMP04", 11},
      {"TMP05", 12},
      {"VOL03", 13},
      {"VOL08", 14},
      {"VOL03", 15},
      {"VOL02", 16},
      {"VOL09", 17},
      {"POW00", 18},
      {"POW01", 19},
      {"POW02", 20},
      {"POW09", 21},
      {"POW11", 22},
      {"CUR00", 23},
      {"CUR10", 24},
      {"CUR20", 25},
      {"CUR11", 27},
      {"CUR15", 28}
    },
    .temperature_bus = 0x09,
    .voltage_bus = 0x0A,
    .power_bus = 0x08,
    .current_bus = 0x07,
  };
  
  std::unique_ptr<eekhdv::sensor> sensors = eekhdv::sensor_factory::make_sensor(cfg);


  
  return 0;
}
