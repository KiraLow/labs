cmake_minimum_required(VERSION 3.6)
project(ansi)

set(CMAKE_C_STANDARD 90)

set(SOURCE_FILES main.c)
add_executable(ansi ${SOURCE_FILES})
target_link_libraries(ansi m)