cmake_minimum_required(VERSION 3.10)
project(ray_tracer_app)

add_subdirectory(ray_tracer)
set(SOURCE_FILES main.cpp)

add_executable(ray_tracer_app ${SOURCE_FILES})
target_link_libraries(ray_tracer_app ray_tracer)
# install(TARGETS divider DESTINATION ${DIVISIBLE_INSTALL_BIN_DIR})