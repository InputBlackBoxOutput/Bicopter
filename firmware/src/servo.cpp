#include "servo.h"

TiltServo::TiltServo(uint8_t pin) : Servo()
{
    ESP32PWM::allocateTimer(1);

    setPeriodHertz(50);
    attach(pin, 90 - MAX_TILT_ANGLE, 90 + MAX_TILT_ANGLE);

    write(90);
}

void TiltServo::setServoAngle(uint8_t requiredPosition)
{
    if (currentPosition == requiredPosition)
    {
        return;
    }

    if (requiredPosition > currentPosition)
    {
        for (uint8_t pos = currentPosition; pos <= requiredPosition; pos++)
        {
            write(pos);
            delayMicroseconds(positionTransitionDelay);
        }
    }
    if (requiredPosition < currentPosition)
    {
        for (uint8_t pos = currentPosition; pos >= requiredPosition; pos--)
        {
            write(pos);
            delayMicroseconds(positionTransitionDelay);
        }
    }

    currentPosition = requiredPosition;
}