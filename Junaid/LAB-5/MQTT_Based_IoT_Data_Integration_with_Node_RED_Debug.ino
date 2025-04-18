#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "BTSGalaxy";            // Replace with the SSID of your WiFi network
const char* password = "khannimra";        // Replace with password of your WiFi network
const char* mqttServer = "test.mosquitto.org";
const int mqttPort = 1883;
const char* mqttUser = "";
const char* mqttPassword = "";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println(". ....................................");

  Serial.print("Connecting to WiFi.");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi!");

  client.setServer(mqttServer, mqttPort);
  while (!client.connected()) {
    Serial.println("Connecting to the MQTT broker...");
    // IMPORTANT: ClientID from the next line (NodoNAPIoT) must be “unique”!!
    if (client.connect("NodoBestFlameSensor/JunaidJavaid", mqttUser, mqttPassword)) {
      Serial.println("Connected to MQTT broker!");
    } else {
      Serial.print("Error connecting with the broker: ");
      Serial.print(client.state());
      delay(2000);
    }
  }
}

void loop() {
  client.loop();
  char str[16];

  sprintf(str, "%u", random(100)); // Simulate the generation of a sensor value

  client.publish("devices/BestFlameSensor/JunaidJavaid", str); // Use same topic as in Node-RED
  Serial.println(str);
  delay(5000);
}
