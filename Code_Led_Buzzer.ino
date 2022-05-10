#include <WiFi.h>
#include <PubSubClient.h>
#include "EasyBuzzer.h"

int LED = 12;
int BUZZER = 5;

const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* mqtt_server = "broker.mqttdashboard.com";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
void setup_wifi() {

  delay(10);

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");

  String letter;
  for (int i = 0; i < length; i++) {
    letter = letter + (char)payload[i];
  }

  Serial.print(letter);
  if(letter == "Warning"){
    digitalWrite(LED, HIGH);
    EasyBuzzer.singleBeep(1000,1000);
  }
  else{
    digitalWrite(LED, LOW);
    EasyBuzzer.stopBeep();
  }
Serial.println();
  
}

void reconnect() {

  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String clientId = "clientId-5tLjfbtB3B";
    clientId += String(random(0xffff), HEX);
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      client.publish("projectultra", "Hello my project");
      client.subscribe("projectultra");
    } 
    else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(500);
    }
  }
}

void setup() {
  
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  EasyBuzzer.setPin(BUZZER); 

  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
