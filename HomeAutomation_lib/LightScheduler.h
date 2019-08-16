/* The design works like this. The client of the LightScheduler is in the AdminConsole subsystem. The AdminConsole
 * instructs the LightScheduler to turn on and off the lights at specific times during the week. Every minute, the
 * LightScheduler is pinged through an OS callback from TimeService. The ping triggers the LightScheduler to check its
 * internally maintained schedule of light control actions. At the appropriate time, the LightScheduler tells the
 * LightController to turn on or off a light by its id.
 * */
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
