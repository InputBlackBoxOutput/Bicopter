#ifndef SERVER_H
#define SERVER_H

#include <Arduino.h>
#include <WiFi.h>
#include "credentials.h"

#include "state.h"
extern ControlState currentState;

#define STEP_PWM 0.25  // Granularity for change in motor PWM
#define STEP_ANGLE 0.1 // Granularity for change in servo motor angle

class ESP32Server
{
public:
    void setup(void);
    void handleClient(unsigned long timestamp, float data[]);

    void handleRouteUp();
    void handleRouteDown();
    void handleRouteForward();
    void handleRouteBackward();
    void handleRouteRight();
    void handleRouteLeft();

    void handleRouteLED();

    // Not implemented: Routes to handle RGB LED
    // void handleRouteLEDR();
    // void handleRouteLEDG();
    // void handleRouteLEDB();

    void handleRouteBatteryVoltage();
    void handleRouteWiFiStrength();

private:
    const char *ssid = WIFI_SSID;
    const char *password = WIFI_PASSWORD;
    WiFiServer server;
    WiFiClient client;

    String header = "";
    String currentLine = "";

    unsigned long currentTime = millis();
    unsigned long previousTime = 0;
    const long timeoutTime = 4000;
};

#endif