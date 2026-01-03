#include "L2Task.h"

L2Task::L2Task(Led* led, Context& context): led(led), context(context) {
    
}

void L2Task::tick(){
    if(context.getState() == State::LANDING || context.getState() == State::TAKE_OFF){
        switch(state){
            case StateL2::ON:
                led->switchOff();
                setState(StateL2::OFF);
                break;
            case StateL2::OFF:
                led->switchOn();
                setState(StateL2::ON);
                break;
        }
    } 
}

void L2Task::setState(StateL2 s) {
    state = s;
}