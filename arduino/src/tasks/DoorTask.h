#ifndef __DOOR_TASK__
#define __DOOR_TASK__

#include "kernel\Task.h"
#include "devices\servoMotor\ServoMotor.h"
#include "model\Context.h"

#define MAX_OPEN_DEGREE 90

class DoorTask: public Task{

public:
    DoorTask(ServoMotor* motor, Context& context);
    void tick();

private:
    enum class DoorState {CLOSE, CLOSING, OPENING, OPEN};

    void setState(DoorState s);
    void startTimeInState();
    long elapsedTimeInState();
    void stopTimeInState();

    ServoMotor* motor;
    Context& context;
    
    int currentPos;
    
    DoorState state;
};

#endif