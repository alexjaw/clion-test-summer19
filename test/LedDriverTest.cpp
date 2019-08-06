//
// Created by alexander on 2019-07-30.
//
#include "catch.hpp"
extern "C" {
#include "LedDriver.h"
}

TEST_CASE("LedsAreOffAfterCreate"){
    uint16_t virtualLeds = 0xffff;
    LedDriver_Create(&virtualLeds);
    REQUIRE(virtualLeds == 0);
}

TEST_CASE("TurnOnLedOne"){
    uint16_t virtualLeds;
    LedDriver_Create(&virtualLeds);
    LedDriver_TurnOn(1);
    REQUIRE(virtualLeds == 1);
}

TEST_CASE("TurnOffLedOne"){
    uint16_t virtualLeds;
    LedDriver_Create(&virtualLeds);
    LedDriver_TurnOn(1);
    REQUIRE(virtualLeds == 1);
    LedDriver_TurnOff(1);
    REQUIRE(virtualLeds == 0);
}

TEST_CASE("TurnOnMultipleLeds"){
    uint16_t virtualLeds;
    LedDriver_Create(&virtualLeds);
    LedDriver_TurnOn(9);
    LedDriver_TurnOn(8);
    REQUIRE(virtualLeds == 0x180);
}

TEST_CASE("TurnOffAnyLed"){
    uint16_t virtualLeds;
    LedDriver_Create(&virtualLeds);
    LedDriver_TurnAllOn();
    REQUIRE(0xffff == virtualLeds);
    LedDriver_TurnOff(8);
    REQUIRE(0xff7f == virtualLeds);
}
