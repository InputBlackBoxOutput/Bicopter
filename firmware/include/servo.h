#include <Arduino.h>
#include <ESP32Servo.h>

#include "connections.h"

class TiltServo : private Servo
{
public:
    const uint8_t maxTiltAngle = 45;             // degrees
    unsigned long positionTransitionDelay = 250; // us

    TiltServo(uint8_t pin);
    void setServoAngle(uint8_t requiredPosition);

private:
    uint8_t currentPosition = 90;
};