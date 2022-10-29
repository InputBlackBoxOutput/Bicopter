#include "IMU.h"

InertialMeasurementUnit::InertialMeasurementUnit()
{
    Wire.begin();
    initialize();
    if (testConnection())
    {
        Serial.println("Unable to connect to MPU6050");
        while (1)
        {
        };
    }
}

void InertialMeasurementUnit::calculateTiltAngles(unsigned long elapsedTime)
{
    getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

    // Calculate tilt angles using accelerometer
    tiltAngleAccelerometer[0] = atan((ay / 16384.0) / sqrt(pow((ax / 16384.0), 2) + pow((az / 16384.0), 2))) * (180 / PI);
    tiltAngleAccelerometer[1] = atan(-1 * (ax / 16384.0) / sqrt(pow((ay / 16384.0), 2) + pow((az / 16384.0), 2))) * (180 / PI);

    // Calculate tilt angles using gyroscope
    tiltAngleGyroscope[0] = (tiltAngle[0] + gx * elapsedTime) * (180 / PI);
    tiltAngleGyroscope[1] = (tiltAngle[1] + gy * elapsedTime) * (180 / PI);

    // Sensor fusion using complementary filter
    tiltAngle[0] = 0.98 * tiltAngleGyroscope[0] + 0.02 * tiltAngleAccelerometer[0];
    tiltAngle[1] = 0.98 * tiltAngleGyroscope[1] + 0.02 * tiltAngleAccelerometer[1];
}