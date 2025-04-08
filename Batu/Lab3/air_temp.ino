#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS D1  // Temperature sensor connected to D1
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

float temperature;  // Stores temperature value

void setup() {
    Serial.begin(9600);
    sensors.begin();
}

void loop() {
    sensors.requestTemperatures(); // Request temperature from sensor
    temperature = sensors.getTempCByIndex(0); // Get temperature in Celsius

    Serial.print("Current Temperature: ");
    Serial.println(temperature);

    if (temperature > 28.0) {
        Serial.println("WARNING: High Temperature! Adjusting Cooling System...");
        activateCoolingSystem();
    } else {
        Serial.println("Temperature is Normal.");
    }

    delay(3000); // Delay for stability
}

void activateCoolingSystem() {
    Serial.println("Cooling System Activated: Adjusting water flow rate...");
    // You can add additional hardware control here (e.g., activating a pump)
}