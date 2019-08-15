//
// Created by alexander on 2019-08-15.
//

#ifndef CLION_TEST_SUMMER19_TIMESERVICE_H
#define CLION_TEST_SUMMER19_TIMESERVICE_H


typedef struct Time
{
    int minuteOfDay;
    int dayOfWeek;
} Time;

void TimeService_Create(void);
void TimeService_Destroy(void);
void TimeService_GetTime(Time *);


#endif //CLION_TEST_SUMMER19_TIMESERVICE_H
