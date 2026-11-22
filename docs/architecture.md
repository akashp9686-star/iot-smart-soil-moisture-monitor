# System Architecture — Project 03

```mermaid
flowchart LR
  A[Soil moisture sensor AO] -->|Analog A0| B[Arduino Uno R3]
  B --> C[Red LED D6: dry]
  B --> D[Green LED D7: adequate moisture]
  B <-->|UART AT commands D10/D11 via level conversion| E[ESP8266 ESP-01]
  E -->|Wi-Fi / HTTP| F[ThingSpeak Field 1]
```

The Uno samples the analog soil sensor, maps the reading to a calibrated percentage and applies the 30% example threshold. The ESP-01 provides Wi-Fi using AT commands; the Uno initiates the ThingSpeak update. The two LEDs provide local status indication.
