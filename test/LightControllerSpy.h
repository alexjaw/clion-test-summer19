//
// Created by alexander on 2019-08-14.
//

#ifndef CLION_TEST_SUMMER19_LIGHTCONTROLLERSPY_H
#define CLION_TEST_SUMMER19_LIGHTCONTROLLERSPY_H

#include "LightController.h"

enum
{
    LIGHT_ID_UNKNOWN = -1, LIGHT_STATE_UNKNOWN = -1,
    LIGHT_OFF = 0, LIGHT_ON = 1
};

int LightControllerSpy_GetLastId(void);
int LightControllerSpy_GetLastState(void);

#endif //CLION_TEST_SUMMER19_LIGHTCONTROLLERSPY_H