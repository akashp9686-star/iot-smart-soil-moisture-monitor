# Project Report — Smart Soil Moisture Monitor

## Problem statement
Monitor soil moisture level in real time and upload readings to ThingSpeak. An RGB LED or buzzer alerts when soil is too dry. Data trends help automate irrigation decisions. This project uses an Arduino Uno paired with an ESP8266 module via AT commands for Wi-Fi.\n\n**Implementation choice:** the handbook's component inventory and wiring table specify separate red and green LEDs. This implementation follows that explicit component/pin list (red D6, green D7) rather than substituting an RGB LED or buzzer.

## Proposed solution
An Arduino Uno reads an analog soil moisture sensor on A0. It converts the reading to a percentage using calibrated dry/wet endpoints. Below 30%, the red LED on D6 is enabled; otherwise the green LED on D7 is enabled. An ESP8266 ESP-01 module, controlled by AT commands over a level-shifted UART connection on D10/D11, uploads the percentage to ThingSpeak Field 1.

## Expected outcome
A locally visible dry/moist status and a cloud trend of moisture readings. Actual accuracy depends on calibration and sensor type.

## Current verification
Hosted firmware compilation can verify source-level compatibility. Physical sensing, calibration, LEDs, Wi-Fi and ThingSpeak tests have not been performed and are not represented as passed.
