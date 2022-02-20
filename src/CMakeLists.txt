cmake_minimum_required(VERSION 3.10)
project(ray_tracer_app)

add_subdirectory(ray_tracer)
set(SOURCE_FILES main.cpp)
set(PROJECTILE projectile.cpp)
set(CANVAS canvas.cpp)

add_executable(ray_tracer_app ${SOURCE_FILES})
add_executable(projectile ${PROJECTILE})
add_executable(canvas ${CANVAS})

target_link_libraries(ray_tracer_app ray_tracer)
target_link_libraries(projectile ray_tracer)
target_link_libraries(canvas ray_tracer)
# install(TARGETS divider DESTINATION ${DIVISIBLE_INSTALL_BIN_DIR})