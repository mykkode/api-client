cmake_minimum_required(VERSION 3.13)
project(test)

set(CMAKE_CXX_STANDARD 14)

add_library(apiClientException SHARED apiClientException.hpp apiClientException.cpp apiClientResponse.cpp apiClientResponse.hpp)

add_library(apiClientSimple SHARED apiClientSimple.hpp apiClientSimple.cpp )

add_library(apiClientResponse SHARED apiClientResponse.cpp apiClientResponse.hpp)

add_executable(test test.cpp)
target_link_libraries(test apiClientSimple apiClientException apiClientResponse curl)