#include <Arduino.h>

#include "servo.h"
#include "motor.h"
#include "LED.h"
#include "IMU.h"
#include "BMS.h"
#include "state.h"
#include "server.h"
#include "PID.h"

InertialMeasurementUnit imu;
TiltServo servoA(SERVO_A_PIN);
TiltServo servoB(SERVO_B_PIN);
Motor motorA(MOTOR_A_PIN);
Motor motorB(MOTOR_B_PIN);
LED led;
BMS bms;

ESP32Server server;
PIDController pid;
ControlState currentState;

#define LOOP_DELAY 300 // ms
unsigned long loopStartTime;
unsigned long elapsedTime;

void setup()
{
  Serial.begin(115200);

  pid.setup();
  server.setup();

  led.blinkLED(led.LED_TAIL, 2);
  loopStartTime = millis();
}

void loop()
{
  server.handleClient();

  // Update servo angles
  servoA.setServoAngle(currentState.servoAngle_A);
  servoA.setServoAngle(currentState.servoAngle_B);

  // Update motor PWM
  motorA.setDutyCyclePWM(currentState.motorPWM_A);
  motorB.setDutyCyclePWM(currentState.motorPWM_B);

  // Turn LEDs ON or OFF
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

  // Read battery voltage and blink tail LED if battery voltage is low
  currentState.batteryVoltage = bms.readBatteryVoltage();
  if (bms.isBatteryVoltageLow())
    led.blinkLED(led.LED_TAIL, 3);

  delay(LOOP_DELAY);

  // Sense tilt and update servo angles to maintain stability using PID
  elapsedTime = millis() - loopStartTime;
  imu.calculateTiltAngles(elapsedTime);
  loopStartTime = millis();

  pid.update();
}