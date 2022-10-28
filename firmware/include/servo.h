#include <Arduino.h>
#include <ESP32Servo.h>

#include "connections.h"
#define MAX_TILT_ANGLE 30 // Max angle of tilt about vertical

class TiltServo : private Servo
{
public:
    unsigned long positionTransitionDelay = 250; // us

    TiltServo(uint8_t pin);
    void setServoAngle(uint8_t requiredPosition);

private:
    uint8_t currentPosition = 90;
};