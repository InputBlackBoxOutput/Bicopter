#include <Arduino.h>

class ControlState
{
public:
    void initControlState();
    void printControlState();

    uint16_t motorPWM_A;
    uint16_t motorPWM_B;
    uint16_t servoAngle_A;
    uint16_t servoAngle_B;
    bool LED;
    double batteryVoltage;
};