#include "led.h"

LED::LED()
{
    pinMode(LED_TAIL, OUTPUT);
    pinMode(LED_A, OUTPUT);
    pinMode(LED_B, OUTPUT);
}

void LED::blinkLED(LED_t led, uint8_t times)
{
    for (uint8_t i = 0; i < times; i++)
    {
        digitalWrite(led, HIGH);
        delay(blinkDelay);
        digitalWrite(led, LOW);
        delay(blinkDelay);
    }
}

inline void LED::turnLEDOn(LED_t led)
{
    digitalWrite(led, HIGH);
}
inline void LED::turnLEDOff(LED_t led)
{
    digitalWrite(led, LOW);
}