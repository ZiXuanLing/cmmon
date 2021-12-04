# CMakeLists.txt
# To generate compile_command.json you must add the parameter 
# DCMAKE_EXPORT_COMPILE_COMMANDS=1

cmake_minimum_required(VERSION 3.0)

add_compile_options(-std=c++11 -pthread)

SET(CMAKE_C_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(thread_pool)

include_directories(common)

add_executable(test test.c thread_pool.c)

