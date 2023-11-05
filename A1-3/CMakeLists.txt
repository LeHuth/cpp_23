cmake_minimum_required(VERSION 3.26)
project(A1_3)

set(CMAKE_CXX_STANDARD 20)

add_executable(A1_3 main.cpp
        lib/vec.h
        lib/tests/test11.cpp
        lib/tests/test11.h)
