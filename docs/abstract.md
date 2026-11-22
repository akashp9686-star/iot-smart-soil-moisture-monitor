# Abstract

The Smart Soil Moisture Monitor reads an analog soil moisture sensor with an Arduino Uno R3, indicates dry and adequately moist conditions using red and green LEDs, and sends moisture readings to ThingSpeak through an ESP8266 ESP-01 Wi-Fi module controlled with UART AT commands. The handbook example uses A0 for the sensor, D6 and D7 for the LEDs, a 30% dry threshold and a 20-second sample/upload interval.

Sensor calibration and physical integration depend on the actual sensor, ESP-01 firmware and power supply. This repository does not claim physical testing has been completed.
