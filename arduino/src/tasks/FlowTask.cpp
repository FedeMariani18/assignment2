#include "FlowTask.h"
#include <Arduino.h>

FlowTask::FlowTask(ContextAlarm& contextAlarm, Context& context, bool& present, double& distance, Command& command):
    contextAlarm(contextAlarm), context(context), present(present), distance(distance), command(command) {

}

const char* commandToString(Command c) {
  switch (c) {
    case Command::TAKE_OFF:      return "TAKE_OFF";
    case Command::LANDING:       return "LANDING";
    default:                     return "UNKNOWN";
  }
}

void FlowTask::tick() {
    switch (context.getState())
    {
        case State::DRONE_INSIDE:
            if (contextAlarm.getAlarmState() != AlarmState::ALARM && command == Command::TAKE_OFF) {
                Serial.println("Cambio stato TAKE_OFF");
                Serial.println(commandToString(command));
                context.setState(State::TAKE_OFF);
            }
        break;

        case State::TAKE_OFF:
            if (contextAlarm.getAlarmState() == AlarmState::ALARM) {
                context.setState(State::FORCED_CLOSING);
            }
            
            if (distance > D1) {
                if (firstTime) {
                    startTimer();
                    firstTime = false;
                } else if (elapsedTime() > T1) {
                    context.setState(State::DRONE_OUT);
                    firstTime = true;
                }
            } else {
                firstTime = true;
            }
        break;

        case State::DRONE_OUT:
            if (present == true &&  command == Command::LANDING) {
                context.setState(State::LANDING);
            }
        break;

        case State::LANDING:
            if (contextAlarm.getAlarmState() == AlarmState::ALARM) {
                context.setState(State::FORCED_CLOSING);
            }

            if (distance < D2) {
                if (firstTime) {
                    startTimer();
                    firstTime = false;
                } else if (elapsedTime() > T2) {
                    context.setState(State::DRONE_INSIDE);
                    firstTime = true;
                }
            } else {
                firstTime = true;
            }
        break;

        case State::FORCED_CLOSING:
            if (distance > D1) {
                if (firstTime) {
                    startTimer();
                    firstTime = false;
                } else if (elapsedTime() > T1) {
                    context.setState(State::DRONE_OUT);
                    firstTime = true;
                }
            } else if (distance < D2) {
                if (firstTime) {
                    startTimer();
                    firstTime = false;
                } else if (elapsedTime() > T2) {
                    context.setState(State::DRONE_INSIDE);
                    firstTime = true;
                }
            } else {
                firstTime = true;
            }
        break;
    }
}

void FlowTask::startTimer() {
    time = millis();
}

long FlowTask::elapsedTime() {
    return millis() - time;
}

