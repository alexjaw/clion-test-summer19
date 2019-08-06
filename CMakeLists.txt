cmake_minimum_required(VERSION 3.12)
project(clion_test_summer19)

set(CMAKE_CXX_STANDARD 17)

include_directories(inc)
include_directories(src)
include_directories(test)

add_executable(clion_test_summer19
        src/main.cpp
        test/LedDriverTest.cpp
        src/LedDriver.c
        inc/LedDriver.h)