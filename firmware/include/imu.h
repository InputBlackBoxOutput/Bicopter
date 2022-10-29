#ifndef IMU_H
#define IMU_H

#include <Arduino.h>
#include <Wire.h>

#include <I2Cdev.h>
#include <MPU6050.h>

#include <math.h>

class InertialMeasurementUnit : private MPU6050
{
public:
    InertialMeasurementUnit();
    void calculateTiltAngles(unsigned long elapsedTime);

    double tiltAngle[2]{}; //[P, Y]

private:
    int16_t ax,
        ay,
        az;
    int16_t gx, gy, gz;

    double tiltAngleAccelerometer[2]{}; //[P, Y]
    double tiltAngleGyroscope[2]{};     //[P, Y]
};

#endif // IMU_H