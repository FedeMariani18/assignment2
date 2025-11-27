#include <Arduino.h>
#include "kernel/Scheduler.h"

Scheduler sched;

void setup() {

}

void loop() {
  sched.schedule();
}
