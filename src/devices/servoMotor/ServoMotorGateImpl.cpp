#include "ServoMotorGateImpl.h"
#include "Arduino.h"

ServoMotorGateImpl::ServoMotorGateImpl(int pin) 
  : ServoMotorImpl(pin) {}

void ServoMotorGateImpl::open(){
    setPosition(90);
}

void ServoMotorGateImpl::close(){
    setPosition(0);
}