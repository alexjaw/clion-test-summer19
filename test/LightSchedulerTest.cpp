//
// Created by alexander on 2019-08-14.
//
#include "catch.hpp"
extern "C" {
#include "LightScheduler.h"
#include "LightControllerSpy.h"
#include "FakeTimeService.h"
}

static void setTime(int day, int minuteOfDay){
    FakeTimeService_SetDay(day);
    FakeTimeService_SetMinute(minuteOfDay);
}

TEST_CASE("LightScheduler") {
    LightController_Create();
    TimeService_Create();
    LightScheduler_Create();

    SECTION("NoChangeToLightsDuringInitialization"){
        REQUIRE(LIGHT_ID_UNKNOWN == LightControllerSpy_GetLastId());
        REQUIRE(LIGHT_STATE_UNKNOWN == LightControllerSpy_GetLastState());
    }

    SECTION("NoScheduleNothingHappens"){
        setTime(MONDAY, 100);
        LightScheduler_WakeUp();
        REQUIRE(LIGHT_ID_UNKNOWN == LightControllerSpy_GetLastId());
        REQUIRE(LIGHT_STATE_UNKNOWN == LightControllerSpy_GetLastState());
    }

    SECTION("ScheduleOnEverydayNotTimeYet"){
        LightScheduler_ScheduleTurnOn(3, EVERYDAY, 1200);
        setTime(MONDAY, 1199);
        LightScheduler_WakeUp();
        REQUIRE(LIGHT_ID_UNKNOWN == LightControllerSpy_GetLastId());
        REQUIRE(LIGHT_STATE_UNKNOWN == LightControllerSpy_GetLastState());
    }

    SECTION("ScheduleOnEverydayItsTime"){
        LightScheduler_ScheduleTurnOn(3, EVERYDAY, 1200);
        setTime(MONDAY, 1200);
        LightScheduler_WakeUp();
        REQUIRE(3 == LightControllerSpy_GetLastId());
        REQUIRE(LIGHT_ON == LightControllerSpy_GetLastState());
    }

    SECTION("ScheduleOffEverydayItsTime"){
        LightScheduler_ScheduleTurnOff(3, EVERYDAY, 1200);
        setTime(MONDAY, 1200);
        LightScheduler_WakeUp();
        REQUIRE(3 == LightControllerSpy_GetLastId());
        REQUIRE(LIGHT_OFF == LightControllerSpy_GetLastState());
    }
}