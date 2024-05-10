#include <cstdint>
#include <linux/i2c-dev.h>
#include <i2c/smbus.h>

#include "sensors/sensor_factory.hpp"


int main (int argc, char *argv[])
{
  eekhdv::sensor_configuration cfg = {
    {
      {"TMP01", "08"},
      {"TMP02", "09"},
      {"TMP03", "10"},
      {"TMP04", "11"},
      {"TMP05", "12"},
      {"VOL03", "13"},
      {"VOL08", "14"},
      {"VOL03", "15"},
      {"VOL02", "16"},
      {"VOL09", "17"},
      {"POW00", "18"},
      {"POW01", "19"},
      {"POW02", "20"},
      {"POW09", "21"},
      {"POW11", "22"},
      {"CUR00", "23"},
      {"CUR10", "24"},
      {"CUR20", "25"},
      {"CUR11", "27"},
      {"CUR15", "28"}
    }
  };
  
  std::unique_ptr sensors = eekhdv::make_sensor(cfg);


  
  return 0;
}
