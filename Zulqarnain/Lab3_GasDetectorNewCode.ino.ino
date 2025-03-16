#define MQ4_PIN 2   // Gas sensor connected to digital pin 2

void setup() {
 Serial.begin(9600);
 pinMode(MQ4_PIN, INPUT);
}

void loop() {
 boolean (MQ4_state) = digitalRead(MQ4_PIN);
 
 if(MQ4_state) // Sensor Output 0 
 {
   Serial.println("No Gas Detected!");
 } 
 else if(MQ4_state) // Sensor Output 1
 {
   Serial.println("Gas Detected");
 }
 delay(1000);  // Check every second
}
