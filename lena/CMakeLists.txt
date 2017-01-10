cmake_minimum_required(VERSION 3.6)
project(lena)

set(CMAKE_C_STANDARD 90)

set(SOURCE_FILES main.c)
add_executable(lena ${SOURCE_FILES})
target_link_libraries(lena m)