cmake_minimum_required(VERSION 3.10)
project(ray_tracer C CXX)

set(SOURCE_FILES
    tracer_math.h
    tracer_math.cpp
    canvas.h
    canvas.cpp
)

add_library(ray_tracer SHARED STATIC ${SOURCE_FILES})

# install(TARGETS division DESTINATION ${DIVISIBLE_INSTALL_LIB_DIR})
# install(FILES division.h DESTINATION ${DIVISIBLE_INSTALL_INCLUDE_DIR})