# Design Decisions — Project 03

- **Controller:** Arduino Uno R3, matching the handbook.
- **Sensor:** Analog-output capacitive or resistive soil moisture sensor, matching the handbook options.
- **Wireless:** ESP8266 ESP-01 controlled through UART AT commands, not ESP8266 Arduino-core firmware.
- **UART pins:** Uno D10 (RX) and D11 (TX), with logic-level conversion as specified.
- **Indicators:** Red D6 for dry soil and green D7 for adequate moisture, each through 220Ω.
- **Cloud field:** ThingSpeak Field 1 stores moisture percentage.
- **Threshold and interval:** 30% and 20 seconds, following the handbook example.
