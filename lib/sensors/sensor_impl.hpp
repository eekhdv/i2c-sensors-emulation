#include <array>
#include <vector>

#include "sensors/sensor.hpp"
#include "sensors/sensor_config.hpp"
#include "measurement_result.hpp"

namespace eekhdv
{

/*
 *
**/
class sensor_impl final : public sensor
{
public:
    /// @brief 
    /// @param sensors 
    sensor_impl(std::array<sensor*, static_cast<std::size_t>(measurement::MAX_NUM)> sensors) : m_sensors{sensors}
    { }

    /// @brief 
    /// @param cfg
    sensor_impl(sensor_configuration& cfg);

    ~sensor_impl() final override;
    
    void measure() final override;

private:
    std::array<sensor*, static_cast<std::size_t>(measurement::MAX_NUM)> m_sensors; ///<
};

} // namespace eekhdv