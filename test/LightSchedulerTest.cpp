//
// Created by alexander on 2019-08-14.
//
#include "catch.hpp"
extern "C" {
#include "LightScheduler.h"
#include "LightControllerSpy.h"
#include "FakeTimeService.h"
}

TEST_CASE("LightController") {
    LightController_Create();
    LightScheduler_Create();

    SECTION("NoChangeToLightsDuringInitialization"){
        REQUIRE(LIGHT_ID_UNKNOWN == LightControllerSpy_GetLastId());
        REQUIRE(LIGHT_STATE_UNKNOWN == LightControllerSpy_GetLastState());
    }

    SECTION("NoScheduleNothingHappens"){
        FakeTimeService_SetDay(MONDAY);
        FakeTimeService_SetMinute(100);
        LightScheduler_WakeUp();
        REQUIRE(LIGHT_ID_UNKNOWN == LightControllerSpy_GetLastId());
        REQUIRE(LIGHT_STATE_UNKNOWN == LightControllerSpy_GetLastState());
    }
}