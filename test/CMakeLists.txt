SET(SOURCE_FILES
        LedDriverTest.cpp
        LightSchedulerTest.cpp
        LightControllerSpyTest.cpp
        LightControllerSpy.c)

add_executable(tests_run ${SOURCE_FILES})
target_link_libraries(tests_run
        LedDriver_lib
        HomeAutomation_lib)