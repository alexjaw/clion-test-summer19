//
// Created by alexander on 2019-08-15.
//
#include "FakeTimeService.h"

static Time fakeTime;

void TimeService_Create(void){
    fakeTime.minuteOfDay = TIME_UNKNOWN;
    fakeTime.dayOfWeek = TIME_UNKNOWN;
};

void TimeService_Destroy(void){};

void TimeService_GetTime(Time * time){
    time->dayOfWeek = fakeTime.dayOfWeek;
    time->minuteOfDay = fakeTime.minuteOfDay;
};

void FakeTimeService_SetDay(int day){
    fakeTime.dayOfWeek = day;
}

void FakeTimeService_SetMinute(int minute){
    fakeTime.minuteOfDay = minute;
}