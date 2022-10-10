#include <Arduino.h>

#include "servo.h"
#include "motor.h"
#include "LED.h"
#include "IMU.h"
#include "BMS.h"

TiltServo servoA(SERVO_A_PIN);
TiltServo servoB(SERVO_B_PIN);

Motor motorA(MOTOR_A_PIN);
Motor motorB(MOTOR_B_PIN);

LED led;

void setup()
{
  Serial.begin(115200);

  led.blinkLED(led.LED_A, 3);
  led.blinkLED(led.LED_B, 3);

  servoA.setServoAngle(80);
  servoA.setServoAngle(80);

  motorA.setDutyCyclePWM(20);
  motorB.setDutyCyclePWM(20);

  Serial.println("Setup complete!");
}

void loop()
{
}