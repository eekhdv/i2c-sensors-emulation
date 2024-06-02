#include <cstdint>
#include <memory>

#include "sensors/sensor_factory.hpp"


int main (int argc, char *argv[])
{
  constexpr uint8_t temp_bus { 0x09 };
  constexpr uint8_t vol_bus  { 0x0A };
  constexpr uint8_t pow_bus  { 0x08 };
  constexpr uint8_t cur_bus  { 0x07 };

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
    .bus_arr = {temp_bus, vol_bus, pow_bus, cur_bus},
  };
  
  std::unique_ptr<eekhdv::sensor> sensors = eekhdv::sensor_factory::make_sensor(cfg);


  
  return 0;
}
