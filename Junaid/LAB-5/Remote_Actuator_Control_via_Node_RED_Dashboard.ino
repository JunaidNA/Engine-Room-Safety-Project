#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Wifi network credentials
const char* ssid = "BTSGalaxy";
const char* password = "khannimra";

// MQTT broker configuration
const char* mqtt_server = "test.mosquitto.org";
const int mqtt_port = 1883;
const char* mqtt_topic = "devices/BestFlameSensor/JunaidJavaid";

// LED that will be turned on/off
const int ledPin = LED_BUILTIN;

WiFiClient espClient;
PubSubClient client(espClient);

// Function to connect to wifi
void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

// Callback function that processes the received MQTT messages
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.println("Message received");
  Serial.print(topic);
  Serial.print(" | ");

  // Convert the payload to string
  String message;
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  Serial.println(message);

  // Control the LED status based on the message
  if (message == "0") {
    digitalWrite(ledPin, LOW);  // Turn off LED
    Serial.println("LED ON");
  } else if (message == "1") {
    digitalWrite(ledPin, HIGH); // Turn on LED
    Serial.println("LED OFF");
  } else {
    Serial.println("Unknown command");
  }
}

// Reconnect to the MQTT broker if the connection is lost
void reconnect() {
  while (!client.connected()) {
    Serial.print("Trying to connect to MQTT broker...");

    // Attempt to connect by specifying the device ID
    if (client.connect("BestFlameSensor/JunaidJavaid")) { // This ID must be unique
      Serial.println("conectado!");

      // Topic subscription
      client.subscribe(mqtt_topic);
      Serial.println("Subscribed to the topic");
    } else {
      Serial.print("connection error, error=");
      Serial.print(client.state());
      Serial.println(" trying again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  // LED pin configuration
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  // Serial port configuration
  Serial.begin(115200);

  // WiFi connection
  setup_wifi();

  // MQTT configuration
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop() {
  // Check if the client is connected
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
