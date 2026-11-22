# Project Report — Glowlogics Project 06: Smart Home Energy Meter

## Objective
Build a current-monitoring prototype using an Arduino Uno, ACS712-20A current sensor, ESP8266 ESP-01 Wi-Fi module, 16x2 I2C LCD and ThingSpeak cloud channel.

## System
The ACS712 analog output is sampled by the Uno at A1. The firmware estimates RMS current from the variance of samples over a one-second window. It displays estimated current and apparent power locally. The ESP-01 receives AT commands over SoftwareSerial and sends ThingSpeak updates.

## Hardware and interface summary
- ACS712 VCC/GND/OUT -> Uno 5V/GND/A1.
- LCD SDA/SCL -> Uno A4/A5.
- ESP-01 TX -> Uno D10; Uno D11 -> ESP-01 RX through level conversion.
- ESP-01 requires a stable regulated 3.3V supply.
- Handbook component list includes a 10µF capacitor; verify exact placement and polarity from the sensor-board documentation before assembly.
- Mains-side current path must be installed and inspected by a qualified electrician.

## Cloud data
ThingSpeak Field 1 is RMS current (A). Field 2 is estimated apparent power (VA). The upload interval is 30 seconds.

## Measurement limitations
The firmware assumes nominal 230V and estimates apparent power as I × 230V. It does not sample voltage or power factor, so it does not measure true active power or billing-grade energy. ACS712 offset, sensitivity, ADC reference and sampling method require calibration.

## Verification status
The source is configured for the Arduino Uno PlatformIO environment. Compilation should be checked in GitHub Actions. No physical sensor calibration, LCD test, ESP-01 Wi-Fi association, ThingSpeak upload or mains installation is claimed as completed. Example CSV values are illustrative only.

## Safety
Mains voltage can cause fatal shock or fire. Never place mains wiring on a breadboard or expose live conductors. A qualified electrician must design and install the isolated, fused and enclosed mains-side fixture.
