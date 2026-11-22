#include <Arduino.h>
#include <SoftwareSerial.h>
#include "config.h"

#ifndef WIFI_SSID
#define WIFI_SSID "YOUR_WIFI_NAME"
#endif
#ifndef WIFI_PASSWORD
#define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"
#endif
#ifndef THINGSPEAK_WRITE_API_KEY
#define THINGSPEAK_WRITE_API_KEY "YOUR_THINGSPEAK_API_KEY"
#endif

// Glowlogics Handbook Project 03 — Smart Soil Moisture Monitor
// ESP-01 TX -> Uno D10 (RX); Uno D11 (TX) -> ESP-01 RX through level converter.
static const uint8_t MOISTURE_PIN = A0;
static const uint8_t RED_LED_PIN = 6;
static const uint8_t GREEN_LED_PIN = 7;
static const int DRY_THRESHOLD_PERCENT = 30;
static const unsigned long SAMPLE_INTERVAL_MS = 20000UL;
static const unsigned long WIFI_JOIN_TIMEOUT_MS = 20000UL;

SoftwareSerial espSerial(10, 11); // RX, TX
unsigned long lastSampleAt = 0;

String readEsp(unsigned long timeoutMs) {
  String response;
  unsigned long started = millis();
  while (millis() - started < timeoutMs) {
    while (espSerial.available()) {
      char c = static_cast<char>(espSerial.read());
      response += c;
    }
  }
  if (response.length()) Serial.print(response);
  return response;
}

String sendAT(const String &command, unsigned long timeoutMs = 2000UL) {
  Serial.print(F(">> "));
  Serial.println(command);
  espSerial.println(command);
  return readEsp(timeoutMs);
}

bool waitFor(const String &command, const String &expected, unsigned long timeoutMs) {
  return sendAT(command, timeoutMs).indexOf(expected) >= 0;
}

bool connectWiFi() {
  sendAT(F("AT+RST"), 3000);
  if (!waitFor(F("AT+CWMODE=1"), "OK", 3000)) return false;
  String join = String(F("AT+CWJAP=\"")) + WIFI_SSID + F("\",\"") + WIFI_PASSWORD + F("\"");
  String response = sendAT(join, WIFI_JOIN_TIMEOUT_MS);
  return response.indexOf("WIFI GOT IP") >= 0 || response.indexOf("OK") >= 0;
}

int readMoisturePercent() {
  int raw = analogRead(MOISTURE_PIN);
  // Handbook calibration example: raw 1023 = dry, raw 300 = wet.
  int percent = map(raw, 1023, 300, 0, 100);
  return constrain(percent, 0, 100);
}

void updateIndicators(int moisturePercent) {
  const bool dry = moisturePercent < DRY_THRESHOLD_PERCENT;
  digitalWrite(RED_LED_PIN, dry ? HIGH : LOW);
  digitalWrite(GREEN_LED_PIN, dry ? LOW : HIGH);
  if (dry) Serial.println(F("ALERT: Soil too dry!"));
  else Serial.println(F("Soil moisture is adequate."));
}

bool uploadToThingSpeak(int moisturePercent) {
  if (String(THINGSPEAK_WRITE_API_KEY) == "YOUR_THINGSPEAK_API_KEY") {
    Serial.println(F("ThingSpeak key not configured; upload skipped."));
    return false;
  }

  String start = sendAT(F("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80"), 5000);
  if (start.indexOf("OK") < 0 && start.indexOf("ALREADY CONNECTED") < 0 &&
      start.indexOf("CONNECT") < 0) return false;

  String request = String(F("GET /update?api_key=")) + THINGSPEAK_WRITE_API_KEY +
    F("&field1=") + String(moisturePercent) +
    F(" HTTP/1.1\r\nHost: api.thingspeak.com\r\nConnection: close\r\n\r\n");

  String sendResponse = sendAT(String(F("AT+CIPSEND=")) + request.length(), 3000);
  if (sendResponse.indexOf(">") < 0) return false;

  espSerial.print(request);
  String result = readEsp(5000);
  sendAT(F("AT+CIPCLOSE"), 1000);
  return result.indexOf("SEND OK") >= 0 || result.indexOf("200 OK") >= 0;
}

void setup() {
  Serial.begin(9600);
  espSerial.begin(9600);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(GREEN_LED_PIN, LOW);

  Serial.println(F("\nGlowlogics Project 03: Smart Soil Moisture Monitor"));
  Serial.println(F("Arduino Uno + analog soil sensor + ESP-01 AT + ThingSpeak"));
  if (connectWiFi()) Serial.println(F("Wi-Fi connected."));
  else Serial.println(F("Wi-Fi connection not confirmed; check ESP-01 supply, baud and credentials."));
}

void loop() {
  if (millis() - lastSampleAt < SAMPLE_INTERVAL_MS) return;
  lastSampleAt = millis();

  int moisture = readMoisturePercent();
  Serial.print(F("Soil moisture: "));
  Serial.print(moisture);
  Serial.println(F("%"));

  updateIndicators(moisture);
  if (uploadToThingSpeak(moisture)) Serial.println(F("ThingSpeak update accepted."));
  else Serial.println(F("ThingSpeak update not confirmed."));
}