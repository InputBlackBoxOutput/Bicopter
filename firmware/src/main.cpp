#include <Arduino.h>
#include "led.h"
LED led;

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  led.blinkLED(led.LED_A, 3);
  led.blinkLED(led.LED_B, 3);

  delay(100);
}