#include <Arduino.h>
#include <ESP32Servo.h>

#include "connections.h"

class TiltServo : private Servo
{
public:
    TiltServo(uint8_t pin);
    void setServoAngle(uint8_t requiredPosition);

private:
    uint8_t currentPosition = 90;
};