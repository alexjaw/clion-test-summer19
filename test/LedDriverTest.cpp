//
// Created by alexander on 2019-07-30.
//
#include "catch.hpp"
extern "C" {
#include "LedDriver.h"
}

TEST_CASE("LedDriver init tests"){
    uint16_t virtualLeds;

    SECTION("LedsAreOffAfterCreate"){
        virtualLeds = 0xffff;
        LedDriver_Create(&virtualLeds);
        REQUIRE(virtualLeds == 0);
    }
}

TEST_CASE("LedDriver tests"){
    uint16_t virtualLeds;
    LedDriver_Create(&virtualLeds);

    SECTION("TurnOnLedOne"){
        LedDriver_TurnOn(1);
        REQUIRE(virtualLeds == 1);
    }

    SECTION("TurnOffLedOne"){
        LedDriver_TurnOn(1);
        REQUIRE(virtualLeds == 1);
        LedDriver_TurnOff(1);
        REQUIRE(virtualLeds == 0);
    }

    SECTION("TurnOnMultipleLeds"){
        LedDriver_TurnOn(9);
        LedDriver_TurnOn(8);
        REQUIRE(virtualLeds == 0x180);
    }

    SECTION("TurnOffAnyLed"){
        LedDriver_TurnAllOn();
        REQUIRE(0xffff == virtualLeds);
        LedDriver_TurnOff(8);
        REQUIRE(0xff7f == virtualLeds);
    }
}
