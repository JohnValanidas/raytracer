cmake_minimum_required(VERSION 3.10)
project(raytracer_tests)

add_subdirectory(lib/googletest)

include_directories(${RAY_TRACER_HEADERS_DIR})
include_directories(lib/googletest/googletest/include)

set(SOURCE_FILES main.cpp src/tracer_math_test.cpp)

add_executable(raytracer_tests ${SOURCE_FILES})
target_link_libraries(raytracer_tests ray_tracer gtest)
