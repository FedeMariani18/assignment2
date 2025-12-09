#include "LCDTask.h"
#include "config.h"

LCDTask::LCDTask(LiquidCrystal_I2C* lcd, Context& context, ContextAlarm& contextAlarm):
    lcd(lcd), context(context), contextAlarm(contextAlarm), lastState(State::DRONE_INSIDE){

}

void LCDTask::tick(){
    State currentState = context.getState();
    if(currentState != lastState){
        if(contextAlarm.getAlarmState() == AlarmState::ALARM){
            lcd->clear();
            lcd->setCursor(0, 0);
            lcd->print("ALARM");
            return;
        } else {
            switch(currentState){
                case State::DRONE_INSIDE:
                    lcd->clear();
                    lcd->setCursor(0, 0);
                    lcd->print("DRONE INSIDE");
                    break;
                case State::TAKE_OFF:
                    lcd->clear();
                    lcd->setCursor(0, 0);
                    lcd->print("TAKE OFF");
                    break;
                case State::DRONE_OUT:
                    lcd->clear();
                    lcd->setCursor(0, 0);
                    lcd->print("DRONE OUT");
                    break;
                case State::LANDING:
                    lcd->clear();
                    lcd->setCursor(0, 0);
                    lcd->print("LANDING");
                    break;
            }
        }
        lastState = currentState;
    }
}