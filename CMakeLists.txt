# set up minimum required version for cmake

cmake_minimum_required(VERSION 3.10)

# set up name for project...
set(PROJECT_NAME RayTracer)

# set the project name and version
project(${PROJECT_NAME} VERSION 1.0)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)


set(RAY_TRACER_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src/ray_tracer)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/bin)

add_subdirectory(src)
add_subdirectory(test)
