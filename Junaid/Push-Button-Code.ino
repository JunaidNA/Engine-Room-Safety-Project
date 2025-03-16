#define BUTTON_PIN D2  // Define the push button pin

void setup() {
    Serial.begin(9600);
    pinMode(BUTTON_PIN, INPUT_PULLUP);  // Enable internal pull-up resistor
}

void loop() {
    int buttonState = digitalRead(BUTTON_PIN);  // Read button state

    if (buttonState == LOW) {  // Button pressed
        Serial.println("Button Pressed!");
        delay(300); // Small delay to avoid multiple detections
    } else {
        Serial.println("Button Not Pressed.");
    }

    delay(500); // Short delay for stability
}