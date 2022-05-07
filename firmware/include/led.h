#include <Arduino.h>
#include "connections.h"

class LED
{
public:
    enum LED_t
    {
        LED_TAIL = LED_TAIL_PIN,
        LED_A = LED_A_PIN,
        LED_B = LED_B_PIN,
    };

    unsigned long blinkDelay = 500;

    LED();
    void blinkLED(LED_t led = LED_TAIL, uint8_t times = 5);
    inline void turnLEDOn(LED_t led = LED_TAIL);
    inline void turnLEDOff(LED_t led = LED_TAIL);
};