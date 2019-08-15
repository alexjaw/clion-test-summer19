//
// Created by alexander on 2019-08-14.
//
#include "catch.hpp"
extern "C" {
#include "LightControllerSpy.h"
}

TEST_CASE("LightController") {
    LightController_Create();

    SECTION("NoChangeToLightsDuringInitialization"){
        REQUIRE(LIGHT_ID_UNKNOWN == LightControllerSpy_GetLastId());
        REQUIRE(LIGHT_STATE_UNKNOWN == LightControllerSpy_GetLastState());
    }
}