#pragma once

// Copy to config.h and edit locally. config.h is ignored by Git.
// Never commit Wi-Fi or MQTT credentials.

#define WIFI_SSID "YOUR_WIFI_NAME"
#define WIFI_PASSWORD "YOUR_WIFI_PASSWORD"

// ESP32 UART2 connection to the PZEM-004T TTL interface.
// Verify exact module interface voltage and pinout before wiring.
#define PZEM_RX_PIN 16
#define PZEM_TX_PIN 17

// MQTT is disabled by default so the repository builds without credentials.
#define MQTT_ENABLED 0
#define MQTT_HOST "YOUR_MQTT_BROKER"
#define MQTT_PORT 1883
#define MQTT_USERNAME ""
#define MQTT_PASSWORD ""
#define MQTT_TOPIC "home/energy/meter01/telemetry"
#define DEVICE_ID "energy-meter-01"

#define SAMPLE_INTERVAL_MS 5000UL
#define MQTT_RECONNECT_INTERVAL_MS 5000UL
