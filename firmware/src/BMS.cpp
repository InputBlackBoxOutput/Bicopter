#include "BMS.h"

BMS::BMS()
{
    analogReadResolution(12);
}

double BMS::readBatteryVoltage()
{
    double batteryVoltage = 0;

    // Approx LiPo battery discharge curve: y = 0.003488 x − 0.227906
    // Better solution: Battery Management IC with over-voltage, under-voltage and over-temperature detection
    for (int i = 0; i < numSamples; i++)
    {
        batteryVoltage += (0.003488 * analogRead(BATT_ADC_PIN) - 0.227906) * 2;
    }

    return batteryVoltage / numSamples;
}

bool BMS::isBatteryVoltageLow()
{
    return (readBatteryVoltage() <= lowBatteryVoltageThreshold) ? true : false;
}