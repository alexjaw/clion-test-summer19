//
// Created by alexander on 2019-08-15.
//
#include "catch.hpp"
extern "C"
{
#include "FakeTimeService.h"
#include "LightScheduler.h"
}

TEST_CASE("FakeTimeService")
{
    TimeService_Create();

    SECTION("Create"){
        Time time;
        TimeService_GetTime(&time);
        REQUIRE(TIME_UNKNOWN == time.minuteOfDay);
        REQUIRE(TIME_UNKNOWN == time.dayOfWeek);
    }

    SECTION("Set")
    {
        Time time;
        FakeTimeService_SetMinute(42);
        FakeTimeService_SetDay(SATURDAY);
        TimeService_GetTime(&time);
        REQUIRE(42 == time.minuteOfDay);
        REQUIRE(SATURDAY == time.dayOfWeek);
    }
}