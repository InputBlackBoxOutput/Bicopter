#include "state.h"

void ControlState::initControlState()
{
    motorPWM_A = 0;
    motorPWM_B = 0;
    servoAngle_A = 0;
    servoAngle_B = 0;
    
    LED = false;
    batteryVoltage = 4.20;
}

void ControlState::printControlState()
{
    Serial.print("Motor A PWM: ");
    Serial.println(motorPWM_A);
    Serial.print("Motor B PWM: ");
    Serial.println(motorPWM_B);

    Serial.print("Servo A angle: ");
    Serial.println(servoAngle_A);
    Serial.print("Servo B angle: ");
    Serial.println(servoAngle_B);

    Serial.print("LED: ");
    Serial.println(LED);

    Serial.print("Battery voltage: ");
    Serial.println(batteryVoltage);
}