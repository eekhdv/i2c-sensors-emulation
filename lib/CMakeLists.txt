add_library(i2c_communication STATIC
    i2c/i2c_comm.cpp
)

add_library(sensors STATIC
    sensors/current_sensor.cpp
    sensors/power_sensor.cpp
    sensors/temperature_sensor.cpp
    sensors/voltage_sensor.cpp
    sensors/sensor_factory.cpp
    sensors/sensor_impl.cpp
)

target_link_libraries(sensors PUBLIC i2c_communication)
