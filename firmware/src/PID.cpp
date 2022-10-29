#include "PID.h"

void PIDController::setup()
{
    for (int i = 0; i < 2; i++)
    {
        pid[i]->SetMode(AUTOMATIC);
        pid[i]->SetOutputLimits(45, 135);
    }
}

void PIDController::update()
{

    sensePitchPID = imu.tiltAngle[0];
    senseYawPID = imu.tiltAngle[1];

    for (int i = 0; i < 2; i++)
    {
        pid[i]->Compute();
    }

    currentState.servoAngle_A = (controlPitchPID + controlYawPID) / 2;
    currentState.servoAngle_B = (controlPitchPID + controlYawPID) / 2;
}