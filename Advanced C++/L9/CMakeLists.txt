cmake_minimum_required(VERSION 3.14)
project(L9)

set(CMAKE_CXX_STANDARD 14)

add_executable(L9 main.cpp header.h parse.cpp binary.cpp basic.cpp unary.cpp)