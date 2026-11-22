# Project 06 — System Architecture
Glowlogics handbook architecture: ACS712-20A senses current; Arduino Uno samples its analog output at A1 and estimates RMS current; the Uno calculates approximate apparent power using an assumed 230 V nominal supply; a 16x2 I2C LCD displays the values; an ESP8266 ESP-01 uses AT commands over SoftwareSerial to upload current and apparent-power fields to ThingSpeak.

```mermaid
flowchart LR
  A[AC load current path] --> B[ACS712-20A]
  B -->|Analog OUT A1| C[Arduino Uno]
  C --> D[16x2 I2C LCD]
  C -->|SoftwareSerial D10/D11| E[ESP8266 ESP-01]
  E -->|Wi-Fi / HTTP| F[ThingSpeak]
```

The AC path is conceptual only. Qualified-person installation, isolation, enclosure and inspection are mandatory. Apparent power is an estimate (I x assumed 230 V), not measured active power.
