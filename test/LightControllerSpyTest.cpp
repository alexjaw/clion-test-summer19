//
// Created by alexander on 2019-08-14.
//
#include "catch.hpp"
extern "C"
{
#include "LightControllerSpy.h"
}

TEST_CASE("LightControllerSpy") {
    LightController_Create();


    SECTION("Create") {
        REQUIRE(LIGHT_ID_UNKNOWN == LightControllerSpy_GetLastId());
        REQUIRE(LIGHT_STATE_UNKNOWN == LightControllerSpy_GetLastState());
    }

    SECTION("RememberTheLastLightIdControlled") {
        LightController_On(10);
        REQUIRE(10 == LightControllerSpy_GetLastId());
        REQUIRE(LIGHT_ON == LightControllerSpy_GetLastState());
    }

    SECTION("RememberTheLastLightIdControlledOff") {
        LightController_Off(42);
        REQUIRE(42 == LightControllerSpy_GetLastId());
        REQUIRE(LIGHT_OFF == LightControllerSpy_GetLastState());
    }
}
