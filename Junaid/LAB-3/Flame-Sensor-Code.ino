int Led = LED_BUILTIN;
int sensorDO = D1; // Digital Output from Flame Sensor

void setup()
{
    pinMode(Led, OUTPUT);
    pinMode(sensorDO, INPUT);
    Serial.begin(9600);
}

void loop()
{
    int flameStatus = digitalRead(sensorDO); // Read the digital output

    Serial.print("Flame Sensor Output: ");
    Serial.println(flameStatus); // Debugging output

    if (flameStatus == LOW) // LOW means fire detected in most sensors
    {
        digitalWrite(Led, LOW); // Turn LED ON (Active LOW)
        Serial.println("NO FIRE");
    }
    else
    {
        digitalWrite(Led, HIGH); // Turn LED OFF
        Serial.println("FIRE IN THE ENGINE ROOM!!!");
    }

    delay(1000); // Faster response
}
