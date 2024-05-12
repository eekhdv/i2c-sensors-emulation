########################################################################
# Project setup
########################################################################
cmake_minimum_required(VERSION 3.20)
project(eekhdv)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include_directories(include/)

########################################################################
# Add headers to cmake project 
########################################################################

# List of directories that contain header files
set(ALL_HEADER_DIRS
  include
)


########################################################################
# Add the subdirectories
########################################################################

add_subdirectory(app)
add_subdirectory(lib)

# if (BUILD_TESTS)
#     add_subdirectory(tests/unittests)
# endif (BUILD_TESTS)
