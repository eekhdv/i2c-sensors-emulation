########################################################################
# Project setup
########################################################################
cmake_minimum_required(VERSION 3.20)
project(srsran)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/modules")
# include(version) # sets version information
# 
# if(NOT CMAKE_BUILD_TYPE)
#    set(CMAKE_BUILD_TYPE Release)
#    message(STATUS "Build type not specified: defaulting to Release.")
# endif(NOT CMAKE_BUILD_TYPE)
# set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "")
# 
# # Generate CMake to include build information
# configure_file(
#   ${PROJECT_SOURCE_DIR}/cmake/modules/build_info.cmake.in
#   ${CMAKE_BINARY_DIR}/build_info.cmake
# )

include_directories(include/)

########################################################################
# Add headers to cmake project 
########################################################################

# List of directories that contain header files
set(ALL_HEADER_DIRS
  app
  lib
  include/
)


########################################################################
# Add the subdirectories
########################################################################

add_subdirectory(app)
add_subdirectory(lib)

# if (BUILD_TESTS)
#     add_subdirectory(tests/unittests)
# endif (BUILD_TESTS)

