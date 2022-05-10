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

private:
    int16_t ax,
        ay,
        az;
    int16_t gx, gy, gz;

    double tiltAngleAccelerometer[2]{}; //[X, Y]
    double tiltAngleGyroscope[2]{};     //[X, Y]
    double tiltAngle[2]{};              //[X, Y]
};
