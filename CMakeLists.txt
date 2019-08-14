cmake_minimum_required(VERSION 3.12)
project(clion_test_summer19)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)

add_executable(LedDriver_run ${SOURCE_FILES})
include_directories(LedDriver_lib)
add_subdirectory(LedDriver_lib)
target_link_libraries(LedDriver_run LedDriver_lib)

add_executable(HomeAutomation_run ${SOURCE_FILES})
include_directories(HomeAutomation_lib)
add_subdirectory(HomeAutomation_lib)
target_link_libraries(HomeAutomation_run HomeAutomation_lib)

add_subdirectory(test)