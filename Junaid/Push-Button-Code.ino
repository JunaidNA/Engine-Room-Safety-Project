int Led = LED_BUILTIN; // Define LED pin
int Button = D1; // Define push button pin
int val; // Define digital variable val

void setup() {
    Serial.begin(9600); // Start Serial communication
    pinMode(Led, OUTPUT); // Set the LED pin as an output
    pinMode(Button, INPUT); // Set the button pin as an input
}

void loop() {
    val = digitalRead(Button); // Read the state of the button

    if (val == HIGH) { // If the button is pressed
        digitalWrite(Led, HIGH); // Turn on LED
        Serial.println("Button Not Pressed!"); // Print to Serial Monitor
    } else {
        digitalWrite(Led, LOW); // Turn off LED
        Serial.println("Button Pressed."); // Print to Serial Monitor
    }

    delay(200); // Short delay for stability
}
