#include <Arduino.h>
#include "kernel/Scheduler.h"
#include "model/Context.h"
#include "model/ContextAlarm.h"

Scheduler sched;
Context context;
ContextAlarm contextAlarm;

void setup() {

}

void loop() {
  sched.schedule();
}
