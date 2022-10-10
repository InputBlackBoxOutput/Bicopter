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
        RGB_LED_R = RGB_LED_R_PIN,
        RGB_LED_G = RGB_LED_G_PIN,
        RGB_LED_B = RGB_LED_B_PIN
    };

    unsigned long blinkDelay = 500; // ms

    LED();
    void blinkLED(LED_t led = LED_TAIL, uint8_t times = 5);
    void turnLEDOn(LED_t led = LED_TAIL);
    void turnLEDOff(LED_t led = LED_TAIL);
};