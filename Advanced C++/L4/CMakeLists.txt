# cmake_minimum_required(VERSION <specify CMake version here>)
project(L5)

set(CMAKE_CXX_STANDARD 11)

add_executable(L5 main.cpp header.h polynomials.cpp)