//
// Created by alexander on 2019-08-15.
//

#ifndef CLION_TEST_SUMMER19_LIGHTSCHEDULER_H
#define CLION_TEST_SUMMER19_LIGHTSCHEDULER_H

enum Day {
    NONE=-1, EVERYDAY=10, WEEKDAY, WEEKEND,
    SUNDAY=1, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY
};

typedef enum Day Day;

void LightScheduler_Create(void);
void LightScheduler_ScheduleTurnOn(int id, Day day, int minuteOfDay);
void LightScheduler_ScheduleTurnOff(int id, Day day, int minuteOfDay);
void LightScheduler_WakeUp(void);

#endif //CLION_TEST_SUMMER19_LIGHTSCHEDULER_H
