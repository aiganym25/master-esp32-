#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>

const char* ssid = "GG";
const char* password = "LANCE001";

byte ip[] = {192, 168, 4, 1};

uint32_t chipId = 0;

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password); 

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  Serial.println("connected");
  
}

void loop() {
  WiFiClient client ;

  if (client.connect(ip, 80) == 1) {
    Serial.println("Connected");
  } else {
    Serial.println("Not Connected");
  }
  delay(10000);

  if (client.connected()) {
    Serial.println("Waiting for Data");
      String message = client.readStringUntil('\n');
      Serial.println(message);
  }
  
}