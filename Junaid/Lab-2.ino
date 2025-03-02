char incomingChar;  // Store incoming character

void setup() {
    Serial.begin(9600);  // Initialize Serial communication
    pinMode(LED_BUILTIN, OUTPUT);  // Set LED as output
    digitalWrite(LED_BUILTIN, HIGH);  // Ensure LED is OFF at start
}

void loop() {
    if (Serial.available() > 0) {  // Check if data is available
        incomingChar = Serial.read();  // Read the incoming character

        // Check the received character
        if (incomingChar == 'M') {
            digitalWrite(LED_BUILTIN, LOW);  // Turn ON LED (Active LOW)
            Serial.println("LED turned ON");
        } else if (incomingChar == 'N') {
            digitalWrite(LED_BUILTIN, HIGH);  // Turn OFF LED
            Serial.println("LED turned OFF");
        }
    }
}
