#ifndef PID_H
#define PID_H

#include <Arduino.h>
#include <PID_v1.h>
#include "state.h"
#include "IMU.h"

extern ControlState currentState;
extern InertialMeasurementUnit imu;

#define KP_PITCH 0.25
#define KI_PITCH 0.5
#define KD_PITCH 0.5

#define KP_YAW 0.25
#define KI_YAW 0.5
#define KD_YAW 0.5

class PIDController
{
public:
    PIDController()
    {
        PID pitchControl(&sensePitchPID, &controlPitchPID, &setpoint, KP_PITCH, KI_PITCH, KD_PITCH, DIRECT);
        PID yawControl(&senseYawPID, &controlYawPID, &setpoint, KP_YAW, KI_YAW, KD_YAW, DIRECT);

        pid[0] = &pitchControl;
        pid[1] = &yawControl;
    }

    void setup();
    void update();

private:
    PID *pid[2];
    double sensePitchPID = 90;
    double senseYawPID = 90;
    double controlPitchPID = 90;
    double controlYawPID = 90;

    double setpoint = 90;
};

#endif // PID_H