#include "DoorTask.h"
#include <Arduino.h>

#define FWD_TIME 1000

DoorTask::DoorTask(ServoMotor* motor, Context& context):
    motor(motor), context(context){

}

void DoorTask::tick(){
    long dt = 0;
    switch (state) {
    case DoorState::CLOSE:
        if(context.getState() == State::LANDING || context.getState() == State::TAKE_OFF){
            setState(DoorState::OPENING);
        }
        break;

    case DoorState::OPENING:
        dt = elapsedTimeInState();
        currentPos = (((float) dt)/FWD_TIME)*MAX_OPEN_DEGREE;
        motor->setPosition(currentPos);
        
        if(currentPos >= 90){
            setState(DoorState::OPEN);
        }
        break;

    case DoorState::OPEN:
        if(context.getState() == State::DRONE_INSIDE || context.getState() == State::DRONE_OUT || 
            context.getState() == State::FORCED_CLOSING){
            setState(DoorState::CLOSING);
        }
        break;

    case DoorState::CLOSING:
        dt = elapsedTimeInState();
        currentPos = (((float) dt)/FWD_TIME)*MAX_OPEN_DEGREE;
        motor->setPosition(currentPos);
        
        if(currentPos <= 0){
            setState(DoorState::CLOSE);
        }
        break;
    }
}

void DoorTask::setState(DoorState s) {
        state = s;
}

void DoorTask::startTimeInState() {

}

long DoorTask::elapsedTimeInState() {

}

void DoorTask::stopTimeInState() {

}