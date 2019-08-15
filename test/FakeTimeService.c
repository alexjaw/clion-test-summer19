//
// Created by alexander on 2019-08-15.
//
#include "FakeTimeService.h"

static Time fakeTime;

void TimeService_Create(void){
    fakeTime.minuteOfDay = -1;
    fakeTime.dayOfWeek = -1;
};

void TimeService_Destroy(void){};

void TimeService_GetTime(Time * time){
    time->dayOfWeek = fakeTime.dayOfWeek;
    time->minuteOfDay = fakeTime.minuteOfDay;
};

void FakeTimeService_SetDay(int day){}

void FakeTimeService_SetMinute(int minute){}