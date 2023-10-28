cmake_minimum_required(VERSION 3.26)
project(A1_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(A1_2 main.cpp
        lib/vec3f.cpp
        lib/vec3f.h
        lib/tests/test11.cpp)
