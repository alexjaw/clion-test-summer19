//
// Created by alexander on 2019-07-30.
//

#ifndef CLION_TEST_SUMMER19_LEDDRIVERC_H
#define CLION_TEST_SUMMER19_LEDDRIVERC_H

#include <stdint.h>

void LedDriver_Create(uint16_t *address);
void LedDriver_TurnOn(uint16_t ledNumber);
void LedDriver_TurnOff(uint16_t ledNumber);
void LedDriver_TurnAllOn(void);

#endif //CLION_TEST_SUMMER19_LEDDRIVERC_H
