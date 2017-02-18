cmake_minimum_required(VERSION 3.6)
project(imageload_template)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c90")

set(SOURCE_FILES main.c qdbmp.c)

add_executable(imageload_template ${SOURCE_FILES})
target_link_libraries(imageload_template m)