#pragma once
// Build-time credentials are supplied as PlatformIO build_flags or local
// untracked config. Never commit real Wi-Fi credentials or ThingSpeak keys.
//
// Example build flags (replace placeholders locally):
// -D WIFI_SSID=\\\"YOUR_WIFI_NAME\\\"
// -D WIFI_PASSWORD=\\\"YOUR_WIFI_PASSWORD\\\"
// -D THINGSPEAK_WRITE_API_KEY=\\\"YOUR_WRITE_API_KEY\\\"
//
// Hardware: Arduino Uno + ACS712-20A + ESP8266 ESP-01 (AT) + 16x2 I2C LCD.
// Firmware uses SoftwareSerial D10 (RX) / D11 (TX), ACS712 analog A1.
// ESP-01 AT baud: 9600. ThingSpeak fields: current RMS (A), estimated apparent power (VA).
