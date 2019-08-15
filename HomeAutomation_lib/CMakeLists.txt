project(HomeAutomation_lib)

set(HEADER_FILES
        LightScheduler.h
        LightController.h
        TimeService.h)

set(SOURCE_FILES
        LightScheduler.c
        LightController.c
        TimeService.c)

add_library(HomeAutomation_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})