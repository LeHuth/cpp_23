cmake_minimum_required(VERSION 3.25)
project(ue1-1)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES main.cpp vec2.cpp vec2.h)
add_executable(ue1-1 ${SOURCE_FILES})