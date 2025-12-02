#include "tasks\TemperatureAlarmTask.h"

TemperatureAlarmTask::TemperatureAlarmTask(ContextAlarm* contextAlarm, Context* context, double temp, Button* resetBtn):
    contextAlarm(contextAlarm), context(context), temp(temp), resetBtn(resetBtn){

}

void TemperatureAlarmTask::tick(){
    
    switch (contextAlarm->getAlarmState()){
        case AlarmState::NORMAL:
            if(context->getState() == State::DRONE_OUT){
                contextAlarm->setAlarmState(AlarmState::NORMAL_OUT);
            }
            if(temp > TEMP1 /*&& duration > T3*/) {
                contextAlarm->setAlarmState(AlarmState::PRE_ALARM);
            }
            break;

        case AlarmState::PRE_ALARM:
            if(temp < TEMP1){
                contextAlarm->setAlarmState(chooseNormalState());
            }
            if(temp > TEMP2 /*&& duration > T4*/) {
                contextAlarm->setAlarmState(AlarmState::PRE_ALARM);
            }
            break;

        case AlarmState::ALARM:
            if(resetBtn->isPressed()){
                contextAlarm->setAlarmState(chooseNormalState());
            }
            break;
        default:
            break;
    }
    
}

AlarmState TemperatureAlarmTask::chooseNormalState(){
    if(context->getState() == State::DRONE_OUT){
        return AlarmState::NORMAL_OUT;
    } else if(context->getState() != State::DRONE_OUT){
        return AlarmState::NORMAL;
    }
}