cmake_minimum_required(VERSION 3.6)
project(untitled)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c90")

set(SOURCE_FILES main.c)
add_executable(untitled ${SOURCE_FILES})
target_link_libraries(untitled m)