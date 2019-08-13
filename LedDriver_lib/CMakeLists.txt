project(LedDriver_lib)

set(HEADER_FILES
        LedDriver.h)

set(SOURCE_FILES
        LedDriver.c)

add_library(LedDriver_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})