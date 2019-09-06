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

static void checkLightState(int id, int state){
    REQUIRE(id == LightControllerSpy_GetLastId());
    REQUIRE(state == LightControllerSpy_GetLastState());
}

TEST_CASE("LightScheduler") {
    LightController_Create();
    TimeService_Create();
    LightScheduler_Create();

    SECTION("NoChangeToLightsDuringInitialization"){
        checkLightState(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
    }

    SECTION("NoScheduleNothingHappens"){
        setTime(MONDAY, 100);
        LightScheduler_WakeUp();
        checkLightState(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
    }

    SECTION("ScheduleOnEverydayNotTimeYet"){
        LightScheduler_ScheduleTurnOn(3, EVERYDAY, 1200);
        setTime(MONDAY, 1199);
        LightScheduler_WakeUp();
        checkLightState(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
    }

    SECTION("ScheduleOnEverydayItsTime"){
        LightScheduler_ScheduleTurnOn(3, EVERYDAY, 1200);
        setTime(MONDAY, 1200);
        LightScheduler_WakeUp();
        checkLightState(3, LIGHT_ON);
    }

    SECTION("ScheduleOffEverydayItsTime"){
        LightScheduler_ScheduleTurnOff(3, EVERYDAY, 1200);
        setTime(MONDAY, 1200);
        LightScheduler_WakeUp();
        checkLightState(3, LIGHT_OFF);
    }

    SECTION("Schedule tuesday but its monday"){
        LightScheduler_ScheduleTurnOn(3, TUESDAY, 1200);
        setTime(MONDAY, 1200);
        LightScheduler_WakeUp();
        checkLightState(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
    }

    SECTION("Schedule tuesday and its tuesday"){
        LightScheduler_ScheduleTurnOn(3, TUESDAY, 1200);
        setTime(TUESDAY, 1200);
        LightScheduler_WakeUp();
        checkLightState(3, LIGHT_ON);
    }

    SECTION("Schedule off tuesday and its tuesday"){
        LightScheduler_ScheduleTurnOff(3, TUESDAY, 1200);
        setTime(TUESDAY, 1200);
        LightScheduler_WakeUp();
        checkLightState(3, LIGHT_OFF);
    }

    SECTION("Schedule weekend and its friday"){
        LightScheduler_ScheduleTurnOn(3, WEEKEND, 1200);
        setTime(FRIDAY, 1200);
        LightScheduler_WakeUp();
        checkLightState(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
    }

    SECTION("Schedule weekend and its saturday"){
        LightScheduler_ScheduleTurnOn(3, WEEKEND, 1200);
        setTime(SATURDAY, 1200);
        LightScheduler_WakeUp();
        checkLightState(3, LIGHT_ON);
    }

    SECTION("Schedule weekdays and its saturday"){
        LightScheduler_ScheduleTurnOn(3, WEEKDAY, 1200);
        setTime(SATURDAY, 1200);
        LightScheduler_WakeUp();
        checkLightState(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
    }

    SECTION("Schedule weekdays and its sunday"){
        LightScheduler_ScheduleTurnOn(3, WEEKDAY, 1200);
        setTime(SUNDAY, 1200);
        LightScheduler_WakeUp();
        checkLightState(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
    }

    SECTION("Schedule weekdays and its monday"){
        LightScheduler_ScheduleTurnOn(3, WEEKDAY, 1200);
        setTime(MONDAY, 1200);
        LightScheduler_WakeUp();
        checkLightState(3, LIGHT_ON);
    }

    SECTION("Schedule weekdays and its friday"){
        LightScheduler_ScheduleTurnOn(3, WEEKDAY, 1200);
        setTime(FRIDAY, 1200);
        LightScheduler_WakeUp();
        checkLightState(3, LIGHT_ON);
    }

    SECTION("Schedule weekdays and its wednesday"){
        LightScheduler_ScheduleTurnOn(3, WEEKDAY, 1200);
        setTime(WEDNESDAY, 1200);
        LightScheduler_WakeUp();
        checkLightState(3, LIGHT_ON);
    }
}