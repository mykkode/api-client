cmake_minimum_required(VERSION 3.10)
project(tester)

set(CMAKE_CXX_STANDARD 14)

add_library(apiClientException SHARED apiClientException.hpp apiClientException.cpp apiClientResponse.cpp apiClientResponse.hpp)

add_library(apiClientSimple SHARED apiClientSimple.hpp apiClientSimple.cpp )

add_library(apiClientResponse SHARED apiClientResponse.cpp apiClientResponse.hpp)

add_executable(tester test.cpp)
target_link_libraries(tester apiClientSimple apiClientException apiClientResponse curl)