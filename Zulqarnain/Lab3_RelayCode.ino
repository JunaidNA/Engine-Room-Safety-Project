int relayPin = D2;

void setup()
{
  pinMode(relayPin, OUTPUT);
}

void loop()
{
  digitalWrite(relayPin, 1);        // turn the relay on
  delay(3000);                      // wait for 3 seconds
  digitalWrite(relayPin, 0);        // turn the relay off
  delay(3000);                      // wait for another 3 seconds
}