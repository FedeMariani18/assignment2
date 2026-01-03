#ifndef __L2_TASK__
#define __L2_TASK__

#include "kernel\Task.h"
#include "devices\led\Led.h"
#include "model\Context.h"

class L2Task: public Task{

public:
    L2Task(Led* led, Context& context);
    void tick();

private:
    enum class StateL2 {ON, OFF};
    void setState(StateL2 s);
    StateL2 state;
    Led* led;
    Context& context;
};

#endif