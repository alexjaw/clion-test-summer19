//
// Created by alexander on 2019-08-14.
//
#include "catch.hpp"
extern "C" {
#include "LightScheduler.h"
#include "LightControllerSpy.h"
#include "FakeTimeService.h"
}

void setTimeTo(int day, int minute)
{
    FakeTimeService_SetDay(day);
    FakeTimeService_SetMinute(minute);
}

void checkLightState(int id, int level)
{
    REQUIRE(id == LightControllerSpy_GetLastId());
    REQUIRE(level == LightControllerSpy_GetLastState());
}

TEST_CASE("LightScheduler") {
    LightController_Create();
    TimeService_Create();
    LightScheduler_Create();

    SECTION("NoChangeToLightsDuringInitialization"){
        checkLightState(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
    }

    SECTION("NoScheduleNothingHappens"){
        setTimeTo(MONDAY, 100);
        LightScheduler_WakeUp();
        checkLightState(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
    }

    SECTION("ScheduleOnEverydayNotTimeYet"){
        LightScheduler_ScheduleTurnOn(3, EVERYDAY, 1200);
        setTimeTo(MONDAY, 1199);
        LightScheduler_WakeUp();
        checkLightState(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
    }

    SECTION("ScheduleOnEverydayItsTime"){
        LightScheduler_ScheduleTurnOn(3, EVERYDAY, 1200);
        setTimeTo(MONDAY, 1200);
        LightScheduler_WakeUp();
        checkLightState(3, LIGHT_ON);
    }

    SECTION("ScheduleOffEverydayItsTime"){
        LightScheduler_ScheduleTurnOff(3, EVERYDAY, 1200);
        setTimeTo(MONDAY, 1200);
        LightScheduler_WakeUp();
        checkLightState(3, LIGHT_OFF);
    }
}