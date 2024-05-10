#include <cstdint>
#include <string>


namespace eekhdv
{
    
using sensor_name = std::string;

enum class measurement : std::size_t
{
  POWER = 0,
  TEMPERATURE,
  VOLTAGE,
  CURRENT,

  MAX_NUM
};

class measurement_result
{
public:
    int64_t get_result() const { return m_res; }

    const std::string& get_dev_addr() const & { return dev_addr; }

private:
    int64_t m_res;
    std::string dev_addr;
};

}