cmake_minimum_required(VERSION 3.25)
project(hello_world)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES main.cpp x.cpp x.h y.h main.cpp)
add_executable(hello_world ${SOURCE_FILES})
