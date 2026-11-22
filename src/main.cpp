#include <Arduino.h>
#include <WiFi.h>
#include <PZEM004Tv30.h>
#include <PubSubClient.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "config.h"

#ifndef PZEM_RX_PIN
#define PZEM_RX_PIN 16
#endif
#ifndef PZEM_TX_PIN
#define PZEM_TX_PIN 17
#endif
#ifndef MQTT_ENABLED
#define MQTT_ENABLED 0
#endif
#ifndef SAMPLE_INTERVAL_MS
#define SAMPLE_INTERVAL_MS 5000UL
#endif
#ifndef MQTT_RECONNECT_INTERVAL_MS
#define MQTT_RECONNECT_INTERVAL_MS 5000UL
#endif

HardwareSerial pzemSerial(2);
PZEM004Tv30 pzem(pzemSerial, PZEM_RX_PIN, PZEM_TX_PIN);
WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

unsigned long lastSampleAt = 0;
unsigned long lastMqttAttemptAt = 0;

struct MeterReading {
  float voltage;
  float current;
  float power;
  float energy;
  float frequency;
  float powerFactor;
};

bool isFiniteInRange(float value, float minimum, float maximum) {
  return isfinite(value) && value >= minimum && value <= maximum;
}

bool readMeter(MeterReading &reading) {
  reading.voltage = pzem.voltage();
  reading.current = pzem.current();
  reading.power = pzem.power();
  reading.energy = pzem.energy();
  reading.frequency = pzem.frequency();
  reading.powerFactor = pzem.pf();

  // Broad plausibility checks only; these are not calibration limits.
  if (!isFiniteInRange(reading.voltage, 0.0f, 300.0f) ||
      !isFiniteInRange(reading.current, 0.0f, 100.0f) ||
      !isFiniteInRange(reading.power, 0.0f, 30000.0f) ||
      !isFiniteInRange(reading.energy, 0.0f, 1000000.0f) ||
      !isFiniteInRange(reading.frequency, 0.0f, 100.0f) ||
      !isFiniteInRange(reading.powerFactor, 0.0f, 1.0f)) {
    Serial.println(F("Invalid or unavailable meter reading; sample skipped."));
    return false;
  }
  return true;
}

void printReading(const MeterReading &r) {
  Serial.printf(
    "Voltage: %.1f V | Current: %.3f A | Power: %.1f W | "
    "Energy: %.3f kWh | Frequency: %.1f Hz | PF: %.2f\n",
    r.voltage, r.current, r.power, r.energy, r.frequency, r.powerFactor
  );
}

#if MQTT_ENABLED
void connectWiFi() {
  if (WiFi.status() == WL_CONNECTED) return;

  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print(F("Connecting to Wi-Fi"));

  const unsigned long started = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - started < 20000UL) {
    delay(500);
    Serial.print('.');
  }
  Serial.println();

  if (WiFi.status() == WL_CONNECTED) {
    Serial.print(F("Wi-Fi connected; IP: "));
    Serial.println(WiFi.localIP());
  } else {
    Serial.println(F("Wi-Fi connection timed out; retrying later."));
  }
}

void connectMqtt() {
  if (mqttClient.connected() || WiFi.status() != WL_CONNECTED) return;
  if (millis() - lastMqttAttemptAt < MQTT_RECONNECT_INTERVAL_MS) return;
  lastMqttAttemptAt = millis();

  bool connected;
  if (strlen(MQTT_USERNAME) > 0) {
    connected = mqttClient.connect(DEVICE_ID, MQTT_USERNAME, MQTT_PASSWORD);
  } else {
    connected = mqttClient.connect(DEVICE_ID);
  }

  Serial.println(connected ? F("MQTT connected.") : F("MQTT connection failed."));
}

void publishReading(const MeterReading &r) {
  if (!mqttClient.connected()) return;

  char payload[256];
  const int written = snprintf(
    payload, sizeof(payload),
    "{\"device\":\"%s\",\"uptime_ms\":%lu,\"voltage_v\":%.2f,"
    "\"current_a\":%.3f,\"power_w\":%.2f,\"energy_kwh\":%.4f,"
    "\"frequency_hz\":%.2f,\"power_factor\":%.3f}",
    DEVICE_ID, millis(), r.voltage, r.current, r.power,
    r.energy, r.frequency, r.powerFactor
  );

  if (written > 0 && written < static_cast<int>(sizeof(payload))) {
    if (!mqttClient.publish(MQTT_TOPIC, payload)) {
      Serial.println(F("MQTT publish failed."));
    }
  } else {
    Serial.println(F("MQTT payload formatting failed."));
  }
}
#endif

void setup() {
  Serial.begin(115200);
  delay(150);
  Serial.println();
  Serial.println(F("Smart Home Energy Meter - ESP32 + PZEM-004T"));

  pzemSerial.begin(9600, SERIAL_8N1, PZEM_RX_PIN, PZEM_TX_PIN);

#if MQTT_ENABLED
  mqttClient.setServer(MQTT_HOST, MQTT_PORT);
  connectWiFi();
#else
  Serial.println(F("MQTT disabled in local configuration."));
#endif
}

void loop() {
#if MQTT_ENABLED
  if (WiFi.status() != WL_CONNECTED) connectWiFi();
  if (!mqttClient.connected()) connectMqtt();
  mqttClient.loop();
#endif

  const unsigned long now = millis();
  if (now - lastSampleAt < SAMPLE_INTERVAL_MS) {
    delay(10);
    return;
  }
  lastSampleAt = now;

  MeterReading reading{};
  if (!readMeter(reading)) return;

  printReading(reading);

#if MQTT_ENABLED
  publishReading(reading);
#endif
}
