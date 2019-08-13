SET(SOURCE_FILES
        LedDriverTest.cpp)

add_executable(tests_run ${SOURCE_FILES})
target_link_libraries(tests_run LedDriver_lib)