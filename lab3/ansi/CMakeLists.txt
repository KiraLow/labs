cmake_minimum_required(VERSION 3.6)
project(loopexample)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c90")

set(SOURCE_FILES loopexample.c)
add_executable(loopexample.c ${SOURCE_FILES})
target_link_libraries(loopexample.c m)