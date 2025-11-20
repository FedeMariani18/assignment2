#ifndef __SERVO_MOTOR_GATE_IMPL__
#define __SERVO_MOTOR_GATE_IMPL__

#include "ServoMotorImpl.h"
#include <arduino.h>

class ServoMotorGateImpl: public ServoMotorImpl {

public:
    ServoMotorGateImpl(int pin) : ServoMotorImpl(pin) {}

    void open();
    void close(); 
};

#endif