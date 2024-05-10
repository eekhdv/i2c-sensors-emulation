add_executable(main
        main.cpp
        )

install(TARGETS main)

target_link_libraries(main
        sensors
        )
