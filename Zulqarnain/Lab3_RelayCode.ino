int relayPin = D2;               // Pin connected to relay

void setup() {
  Serial.begin(9600);            // Start serial communication
  pinMode(relayPin, OUTPUT);     // Set relay pin as output
}

void loop() {
  Serial.println("Relay ON");
  digitalWrite(relayPin, 1);     // Turn relay ON
  delay(1000);                   // Wait for 1 second
  
  Serial.println("Relay OFF");
  digitalWrite(relayPin, 0);     // Turn relay OFF
  delay(1000);                   // Wait for 1 second
}
