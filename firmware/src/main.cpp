#include <Arduino.h>

#define STEP_PWM 0.25  // Granularity for change in motor PWM
#define STEP_ANGLE 0.1 // Granularity for change in servo motor angle
#define LOOP_DELAY 300 // ms

#include "servo.h"
#include "motor.h"
#include "LED.h"
#include "IMU.h"
#include "BMS.h"
#include "state.h"

TiltServo servoA(SERVO_A_PIN);
TiltServo servoB(SERVO_B_PIN);

Motor motorA(MOTOR_A_PIN);
Motor motorB(MOTOR_B_PIN);

LED led;
BMS bms;

ControlState currentState;

void setup()
{
  Serial.begin(115200);
  led.blinkLED(led.LED_TAIL, 3);

  Serial.println("Setup complete!");
}

void loop()
{
  servoA.setServoAngle(currentState.servoAngle_A);
  servoA.setServoAngle(currentState.servoAngle_B);

  motorA.setDutyCyclePWM(currentState.motorPWM_A);
  motorB.setDutyCyclePWM(currentState.motorPWM_B);

  if (currentState.LED)
  {
    led.turnLEDOn(led.LED_A);
    led.turnLEDOn(led.LED_B);
    led.turnLEDOn(led.LED_TAIL);
  }
  else
  {
    led.turnLEDOff(led.LED_A);
    led.turnLEDOff(led.LED_B);
    led.turnLEDOff(led.LED_TAIL);
  }

  currentState.batteryVoltage = bms.readBatteryVoltage();
  delay(LOOP_DELAY);
}