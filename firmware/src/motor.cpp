#include "motor.h"

Motor::Motor(uint8_t pin) : ESP32PWM()
{
    attachPin(pin, 1000, 10);
    write(0);
}

void Motor::setDutyCyclePWM(uint8_t duty)
{
    if (duty > 100)
    {
        return;
    }
    writeScaled(duty / 100);
}