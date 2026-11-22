# Abstract

This repository documents Glowlogics Handbook Project 06: a Smart Home Energy Meter using Arduino Uno, ACS712-20A current sensor, ESP8266 ESP-01 Wi-Fi module, 16x2 I2C LCD and ThingSpeak. The Uno calculates RMS current from 1,000 ADC samples, displays current and estimated apparent power, and sends telemetry through the ESP-01 AT interface.

The apparent-power value uses an assumed 220V supply and is not a measurement of true active power. Physical calibration, mains installation, LCD operation, ESP-01 connectivity and live ThingSpeak delivery remain unverified.