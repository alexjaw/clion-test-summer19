//
// Created by alexander on 2019-07-30.
//
#include "LedDriver.h"

static uint16_t * ledsAddress;

void LedDriver_Create(uint16_t * address){
    ledsAddress = address;
    *ledsAddress = 0;
}

void LedDriver_TurnOn(uint16_t ledNumber){
    *ledsAddress |= 1<<(ledNumber-1);
}

void LedDriver_TurnOff(uint16_t ledNumber){
    *ledsAddress &= ~(1<<(ledNumber-1));
}

void LedDriver_TurnAllOn(void){
    *ledsAddress = 0xffff;
}