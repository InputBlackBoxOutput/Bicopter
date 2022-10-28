#ifndef BMS_H
#define BMS_H

#include <Arduino.h>
#include "connections.h"

class BMS
{
public:
    BMS();
    double readBatteryVoltage();
    bool isBatteryVoltageLow();

private:
    const int numSamples = 5;
    const double lowBatteryVoltageThreshold = 3.20;
};

#endif