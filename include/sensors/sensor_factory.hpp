#include <memory>

#include "sensor.hpp"

namespace eekhdv
{
    
    std::unique_ptr<sensor> make_sensor();
}
