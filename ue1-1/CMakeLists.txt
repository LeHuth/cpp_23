cmake_minimum_required(VERSION 3.25)
project(ue1-1)

set(CMAKE_CXX_STANDARD 20)

set(SOURCE_FILES main.cpp vec3f.cpp vec3f.h test11.cpp test11.h)
add_executable(ue1-1 ${SOURCE_FILES})