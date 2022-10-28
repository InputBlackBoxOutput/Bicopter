#include "server.h"

void ESP32Server::setup()
{
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    server.begin();
}

// Route: GET /up
void ESP32Server::handleRouteUp()
{
    Serial.println("GET /up");

    currentState.motorPWM_A = currentState.motorPWM_A + STEP_PWM;
    currentState.motorPWM_B = currentState.motorPWM_B + STEP_PWM;

    currentState.servoAngle_A = 90;
    currentState.servoAngle_B = 90;

    client.print("{\"");
    client.print("Operation\":\"UP");
    client.print("\"}");
}

// Route: GET /down
void ESP32Server::handleRouteDown()
{
    Serial.println("GET /down");

    currentState.motorPWM_A = currentState.motorPWM_A - STEP_PWM;
    currentState.motorPWM_B = currentState.motorPWM_B - STEP_PWM;

    currentState.servoAngle_A = 90;
    currentState.servoAngle_B = 90;

    client.print("{\"");
    client.print("Operation\":\"DOWN");
    client.print("\"}");
}

// Route: GET /forward
void ESP32Server::handleRouteForward()
{
    Serial.println("GET /forward");

    currentState.motorPWM_A = currentState.motorPWM_A;
    currentState.motorPWM_B = currentState.motorPWM_B;

    currentState.servoAngle_A = currentState.servoAngle_A + STEP_ANGLE;
    currentState.servoAngle_B = currentState.servoAngle_B + STEP_ANGLE;

    client.print("{\"");
    client.print("Operation\":\"FORWARD");
    client.print("\"}");
}

// Route: GET /backward
void ESP32Server::handleRouteBackward()
{
    Serial.println("GET /backward");

    currentState.motorPWM_A = currentState.motorPWM_A;
    currentState.motorPWM_B = currentState.motorPWM_B;

    currentState.servoAngle_A = currentState.servoAngle_A - STEP_ANGLE;
    currentState.servoAngle_B = currentState.servoAngle_B - STEP_ANGLE;

    client.print("{\"");
    client.print("Operation\":\"BACKWARD");
    client.print("\"}");
}

// Route: GET /left
void ESP32Server::handleRouteLeft()
{
    Serial.println("GET /left");

    currentState.motorPWM_A = currentState.motorPWM_A;
    currentState.motorPWM_B = currentState.motorPWM_B;

    currentState.servoAngle_A = currentState.servoAngle_A + STEP_ANGLE;
    currentState.servoAngle_B = currentState.servoAngle_B - STEP_ANGLE;

    client.print("{\"");
    client.print("Operation\":\"LEFT");
    client.print("\"}");
}

// Route: GET /right
void ESP32Server::handleRouteRight()
{
    Serial.println("GET /right");

    currentState.motorPWM_A = currentState.motorPWM_A;
    currentState.motorPWM_B = currentState.motorPWM_B;

    currentState.servoAngle_A = currentState.servoAngle_A - STEP_ANGLE;
    currentState.servoAngle_B = currentState.servoAngle_B + STEP_ANGLE;

    client.print("{\"");
    client.print("Operation\":\"RIGHT");
    client.print("\"}");
}

// Route: GET /led-lights
void ESP32Server::handleRouteLED()
{
    Serial.println("GET /led-lights");

    if (currentState.LED)
    {
        currentState.LED = false;
    }
    else
    {
        currentState.LED = true;
    }

    client.print("{\"");
    client.print("Operation\":\"LED");
    client.print("\"}");
}

// Route: GET /battery-voltage
void ESP32Server::handleRouteBatteryVoltage()
{
    Serial.println("GET /battery-voltage");

    client.print("{\"");
    client.print("Voltage\":\"");
    client.print(currentState.batteryVoltage);
    client.print("\"}");
}

// Route: GET /wifi-strength
void ESP32Server::handleRouteWiFiStrength()
{
    Serial.println("GET /wifi-strength");

    client.print("{\"");
    client.print("Strength\":\"");
    client.print(WiFi.RSSI()); // Received Signal Strength Indicator
    client.print("\"}");
}

void ESP32Server::handleClient(unsigned long timestamp, float data[])
{
    client = server.available();

    if (client)
    {
        currentTime = millis();
        previousTime = millis();

        while (client.connected() && currentTime - previousTime <= timeoutTime)
        {
            currentTime = millis();
            if (client.available())
            {
                char c = client.read();
                header += c;

                if (c == '\n')
                {
                    if (currentLine.length() == 0)
                    {

                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-type:text/json");
                        client.println("Connection: close");
                        client.println();

                        if (header.indexOf("GET /up") >= 0)
                            handleRouteUp();
                        else if (header.indexOf("GET /down") >= 0)
                            handleRouteDown();
                        else if (header.indexOf("GET /forward") >= 0)
                            handleRouteForward();
                        else if (header.indexOf("GET /backward") >= 0)
                            handleRouteBackward();
                        else if (header.indexOf("GET /left") >= 0)
                            handleRouteLeft();
                        else if (header.indexOf("GET /right") >= 0)
                            handleRouteRight();
                        else if (header.indexOf("GET /led-lights") >= 0)
                            handleRouteLED();
                        else if (header.indexOf("GET /") >= 0)
                        {
                            Serial.println("GET /");
                            client.print("{\"");
                            client.print("Connected\":\"");
                            client.print(WiFi.localIP());
                            client.print("\"}");
                        }
                        else
                        {
                            Serial.println("Invalid Route!");
                        }

                        client.println();
                        break;
                    }
                    else
                    {
                        currentLine = "";
                    }
                }
                else if (c != '\r')
                {
                    currentLine += c;
                }
            }
        }

        header = "";
        client.stop();
    }
}