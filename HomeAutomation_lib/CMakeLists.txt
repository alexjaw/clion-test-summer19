project(HomeAutomation_lib)

set(HEADER_FILES
        LightController.h)

set(SOURCE_FILES
        LightController.c)

add_library(HomeAutomation_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})