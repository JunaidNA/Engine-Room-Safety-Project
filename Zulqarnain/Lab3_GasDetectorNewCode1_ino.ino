int pin_mq4 = D1; // D1 is used for reading the sensor data

void setup() {
    Serial.begin(9600);
    pinMode(pin_mq4, INPUT);
}

void loop() {
    boolean mq4_state = digitalRead(pin_mq4); // Read the sensor output

    if (mq4_state) { // If the sensor output is HIGH (1)
        Serial.println("No gas detected");
    } else { // If the sensor output is LOW (0)
        Serial.println("Gas detected!");
    }
    
    delay(2000); // Wait 1 second before the next reading
}
