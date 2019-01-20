cmake_minimum_required(VERSION 3.13)
project(test)

set(CMAKE_CXX_STANDARD 14)

add_library(apiClientException SHARED apiClientException.hpp apiClientException.cpp )

add_library(apiClientSimple SHARED apiClientSimple.hpp apiClientSimple.cpp )

add_executable(test test.cpp)
target_link_libraries(test apiClientSimple apiClientException curl)