#include <WiFi.h>
#include <PubSubClient.h>

int trigPin = 4;
int echoPin = 2;
int duration;
int distance;
int SW = 22;

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
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  pinMode(SW, INPUT);

  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  char message[10];
  if ((digitalRead(SW) == 0)){
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2);
    strcpy(message, "Close");
  }

  else{
    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance= (duration*0.034/2);
    
    if ((distance < 50)){
      strcpy(message, "Warning");
    }
    else{
      strcpy(message, "Open");
    }
  }
  
  client.publish("projectultra", message);
  delay(1000);
  
}
