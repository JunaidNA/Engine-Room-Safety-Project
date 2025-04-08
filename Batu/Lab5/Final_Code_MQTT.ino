#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// WiFi credentials
const char* ssid = "Batu";
const char* password = "Batu1234";

// MQTT broker settings
const char* mqtt_server = "test.mosquitto.org";
const int mqtt_port = 1883;
const char* mqtt_sub_topic = "devices/NAPIoT-P2-Rec";
const char* mqtt_pub_topic = "devices/NAPIoT-P2";

// LED pin
const int ledPin = LED_BUILTIN;

// Temperature sensor setup
#define ONE_WIRE_BUS D1
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
float temperature;

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  delay(10);
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected!");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message received on topic: ");
  Serial.println(topic);

  String message;
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  Serial.println("Payload: " + message);

  if (message == "0") {
    digitalWrite(ledPin, LOW);  // Turn OFF LED
    Serial.println("LED OFF");
  } else if (message == "1") {
    digitalWrite(ledPin, HIGH); // Turn ON LED
    Serial.println("LED ON");
  } else {
    Serial.println("Unknown command");
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Trying to connect to MQTT broker...");
    if (client.connect("NAPIoT-P2-Rec")) {
      Serial.println("connected!");
      client.subscribe(mqtt_sub_topic);
      Serial.println("Subscribed to topic.");
    } else {
      Serial.print("Error: ");
      Serial.print(client.state());
      delay(5000);
    }
  }
}

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  Serial.begin(115200);
  setup_wifi();

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);

  sensors.begin(); // Initialize temperature sensor
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  sensors.requestTemperatures();
  temperature = sensors.getTempCByIndex(0);
  Serial.print("Current Temperature: ");
  Serial.println(temperature);

  char tempStr[8];
  dtostrf(temperature, 4, 2, tempStr);
  client.publish(mqtt_pub_topic, tempStr);

  delay(5000);
}