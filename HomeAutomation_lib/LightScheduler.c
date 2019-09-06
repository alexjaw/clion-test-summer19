//
// Created by alexander on 2019-08-15.
//
#include "LightScheduler.h"
#include "TimeService.h"
#include "LightController.h"

/* We’ll need a struct to hold the information about each schedule light control. With that struct we’ll create an array
 * to hold the 128 separate scheduled events (128 is the design limit from the requirements).
 * LightScheduler_ScheduleTurnOn, and similar operations, will use the next unused slot in the array.
 * LightScheduler_WakeUp will go through the array and see whether any scheduled lights need to be controlled.
 * */
typedef struct {
    int id;           // The id of a lamp
    Day day;          // See Day for different options
    int minuteOfDay;  // Minute that the lamp should be turned on/off
    int event;        // TURN_ON/TURN_OFF
} ScheduledLightEvent;

static ScheduledLightEvent scheduledEvent;

static enum {UNUSED=-1, TURN_OFF=0, TURN_ON};

static void scheduleEvent(int id, Day day, int minuteOfDay, int event){
    scheduledEvent.id = id;
    scheduledEvent.day = day;
    scheduledEvent.minuteOfDay = minuteOfDay;
    scheduledEvent.event = event;
}

static void operateLight(ScheduledLightEvent * lightEvent){
    if(lightEvent->event == TURN_ON) {
        LightController_On(lightEvent->id);
    }else if(lightEvent->event == TURN_OFF){
        LightController_Off(lightEvent->id);
    }
}

static void processEventDueTime(Time * time, ScheduledLightEvent * lightEvent){
    if(lightEvent->id == UNUSED){ return; }

    if(lightEvent->day != EVERYDAY){ return; }

    if(lightEvent->minuteOfDay != time->minuteOfDay){ return; }

    operateLight(lightEvent);
}

void LightScheduler_Create(void){
    //scheduledEvent.day = EVERYDAY;
}

void LightScheduler_ScheduleTurnOn(int id, Day day, int minuteOfDay){
    scheduleEvent(id, day, minuteOfDay, TURN_ON);
}

void LightScheduler_ScheduleTurnOff(int id, Day day, int minuteOfDay){
    scheduleEvent(id, day, minuteOfDay, TURN_OFF);
}

void LightScheduler_WakeUp(void) {
    Time time;
    TimeService_GetTime(&time);

    processEventDueTime(&time, &scheduledEvent);
}
