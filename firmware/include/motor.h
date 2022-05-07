#include <Arduino.h>
#include <ESP32PWM.h>

#include "connections.h"

class Motor : private ESP32PWM
{
public:
    Motor(uint8_t pin);
    void setDutyCyclePWM(uint8_t duty);
};
