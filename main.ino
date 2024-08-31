#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>
#include "WiFiCredentials.h"

const int outputPin = 5;
const unsigned long TRIGGER_DURATION = 10000;        // Duration to keep the pin HIGH in milliseconds
const unsigned long WIFI_TIMEOUT = 10000;            // WiFi connection timeout in milliseconds
const unsigned long WIFI_RECONNECT_INTERVAL = 5000;  // Interval to attempt reconnecting WiFi

AsyncWebServer server(80);
bool triggerActive = false;
unsigned long triggerStartTime = 0;

void setup() {
  Serial.begin(115200);

  pinMode(outputPin, OUTPUT);
  digitalWrite(outputPin, LOW);

  setupWiFi();
  setupServer();
}

void loop() {
  handleTrigger();
  handleWiFiReconnect();
}

void setupWiFi() {
  WiFi.begin(ssid, password);
  unsigned long startAttemptTime = millis();

  // Wait for connection or timeout after WIFI_TIMEOUT
  while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < WIFI_TIMEOUT) {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Connected to WiFi");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("Failed to connect to WiFi. Will retry...");
  }
}

void setupServer() {
  // Define the server route
  server.on("/trigger", HTTP_GET, [](AsyncWebServerRequest *request) {
    digitalWrite(outputPin, HIGH);
    triggerActive = true;
    triggerStartTime = millis();
    request->send(200, "text/plain", "Pin triggered!");
  });

  server.begin();
  Serial.println("HTTP server started");
}

void handleTrigger() {
  // Check if trigger is active and handle timing
  if (triggerActive && millis() - triggerStartTime >= TRIGGER_DURATION) {
    digitalWrite(outputPin, LOW);
    triggerActive = false;
    Serial.println("Pin turned off");
  }
}

void handleWiFiReconnect() {
  // Reconnect to WiFi if disconnected
  if (WiFi.status() != WL_CONNECTED) {
    static unsigned long lastReconnectAttempt = 0;
    if (millis() - lastReconnectAttempt >= WIFI_RECONNECT_INTERVAL) {
      lastReconnectAttempt = millis();
      Serial.println("Attempting to reconnect to WiFi...");
      WiFi.begin(ssid, password);
    }
  }
}
