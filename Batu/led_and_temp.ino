#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS D1  // Temperature sensor connected to D1
#define LED_PIN D2       // LED connected to D2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

float temperature;  // Stores temperature value

void setup() {
    Serial.begin(9600);       // Start Serial Monitor
    sensors.begin();          // Initialize temperature sensor
    pinMode(LED_PIN, OUTPUT); // Initialize LED pin as output
    Serial.println("System Initialized. Monitoring Temperature...");
}

void loop() {
    Serial.println("Reading Temperature...");
    sensors.requestTemperatures(); // Request temperature from sensor
    temperature = sensors.getTempCByIndex(0); // Get temperature in Celsius

    Serial.print("Current Temperature: ");
    Serial.println(temperature);

    if (temperature > 22.0) {
        Serial.println("WARNING: High Temperature! Turning ON LED...");
        digitalWrite(LED_PIN, HIGH); // Turn LED ON
    } else {
        Serial.println("Temperature Normal. Turning OFF LED...");
        digitalWrite(LED_PIN, LOW); // Turn LED OFF
    }

    delay(3000); // Delay before checking again
}
