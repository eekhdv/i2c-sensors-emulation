add_executable(main
        main.cpp
        )

install(TARGETS main RUNTIME)

target_link_libraries(main
        sensors
        i2c_communication
        )

target_include_directories(main PRIVATE ../include ../include/sensors)
