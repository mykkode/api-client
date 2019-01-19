cmake_minimum_required(VERSION 3.13)
project(test)

set(CMAKE_CXX_STANDARD 14)

add_library(test test.cpp apiClientSimple.cpp apiClientSimple.hpp)