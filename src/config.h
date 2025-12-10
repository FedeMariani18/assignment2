#define BT_PIN 0
#define LED1_PIN 0
#define LED2_PIN 0
#define RED_LED_PIN 0
#define MOTOR_PIN 0
#define PIR_PIN 0
#define SONAR_ECHO_PIN 0
#define SONAR_TRIG_PIN 0
#define SONAR_TIMEOUT 0
#define TEMP_PIN 0

#define LCD_ADRR 0
#define LCD_COLS 0
#define LCD_ROWS 0

#define T1 200
#define T2 200
#define T3 1000
#define T4 1000

#define TEMP1 20
#define TEMP2 24

#define PERIOD 
#define FLOW_TASK_PERIOD 20
#define TEMPERATURE_ALARM_TASK_PERIOD 100
#define TEMP_TASK_PERIOD 200
#define L1_TASK_PERIOD 250
#define L2_TASK_PERIOD 500
#define L3_TASK_PERIOD 250
#define DISTANCE_TASK_PERIOD 50
#define PRESENCE_TASK_PERIOD 100
#define DOOR_TASK_PERIOD 50
#define LCD_TASK_PERIOD 250
#define MESSAGE_MANAGER_TASK_PERIOD 250

#define D1 1
#define T1 1
#define D2 1
#define D2 1

enum class State {
    DRONE_INSIDE,
    TAKE_OFF,
    DRONE_OUT,
    LANDING,
    FORCED_CLOSING
};

enum class AlarmState {
    NORMAL_OUT,
    NORMAL,
    PRE_ALARM,
    ALARM
};

enum class Command {
    TAKE_OFF,
    LANDING,
};