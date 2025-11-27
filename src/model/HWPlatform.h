#ifndef __HW_PLATFORM__
#define __HW_PLATFORM__

#include "LiquidCrystal_I2C.h"
#include "config.h"
#include "devices/button/Button.h"
#include "devices/led/Led.h"
#include "devices/servoMotor/ServoMotor.h"
#include "devices/presenceSensor/PresenceSensor.h"
#include "devices/proximitySensor/ProximitySensor.h"
#include "devices/tempSensor/TempSensor.h"

class HWPlatform {

public:
  HWPlatform();
  void init();
  void test();

  Button* getResetButton();
  Led*  getLed1();
  Led*  getLed2();
  Led*  getLed3();
  ServoMotor* getMotor();
  PresenceSensor* getPresenceSensor(); 
  ProximitySensor* getProximitySensor();
  TempSensor* getTempSensor();
  LiquidCrystal_I2C* getLcd();
  

private:
  Button* resetButton;
  Led*  led1;
  Led*  led2;
  Led*  led3;
  ServoMotor* motor;
  PresenceSensor* presenceSensor; 
  ProximitySensor* proximitySensor;
  TempSensor* tempSensor;
  LiquidCrystal_I2C* lcd;
};

#endif
