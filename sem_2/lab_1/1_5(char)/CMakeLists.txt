cmake_minimum_required(VERSION 3.6)
project(1_5)

set(CMAKE_C_STANDARD 90)

set(SOURCE_FILES main.c)
add_executable(1_5 ${SOURCE_FILES})
target_link_libraries(1_5 m)