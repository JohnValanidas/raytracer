cmake_minium_rquired(VERSION 3.10)

set(this raytracer_tests)

add_subdirectory(lib/googltest)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
	gtest_main
	RayTracer	
)


add_test(
	NAME ${This}
	COMMAND ${This}	
)

