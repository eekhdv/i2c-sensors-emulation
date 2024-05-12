add_library(sensors
    sensors/current_sensor.cpp
    sensors/power_sensor.cpp
    sensors/temperature_sensor.cpp
    sensors/voltage_sensor.cpp
    sensors/sensor_factory.cpp
    sensors/sensor_impl.cpp
)

#target_link_libraries(...)
