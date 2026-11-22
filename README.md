# Project 03 — Smart Soil Moisture Monitor

**Glowlogics IoT Projects Handbook | MEDIUM | Arduino Uno + Soil Sensor + ESP8266 ESP-01 (AT) + ThingSpeak**

## Problem statement

Monitor soil moisture level in real time and upload readings to ThingSpeak. A red LED alerts when soil is too dry, while a green LED indicates adequate moisture. The uploaded moisture trend can help inform irrigation decisions. The system uses an Arduino Uno to read the analog soil sensor and an ESP8266 ESP-01 controlled through UART AT commands for Wi-Fi connectivity.

## Exact handbook hardware

| Component | Quantity | Purpose |
|---|---:|---|
| Arduino Uno R3 | 1 | Main controller |
| Analog soil moisture sensor (capacitive or resistive) | 1 | Soil moisture measurement |
| ESP8266 ESP-01 | 1 | Wi-Fi using AT commands |
| Logic-level converter | 1 | 5V ↔ 3.3V UART level conversion |
| Red LED + 220Ω resistor | 1 each | Dry-soil alert |
| Green LED + 220Ω resistor | 1 each | Moist-soil indicator |
| Jumper wires | 10 | Connections |
| Breadboard | 1 | Low-voltage prototyping |

## Handbook pin mapping

| Signal | Arduino Uno connection |
|---|---|
| Soil sensor VCC | 5V |
| Soil sensor GND | GND |
| Soil sensor AO | A0 |
| ESP-01 VCC and CH_PD/EN | Regulated 3.3V supply |
| ESP-01 GND | Common GND |
| ESP-01 TX → Uno RX | D10 through suitable level conversion |
| Uno TX → ESP-01 RX | D11 through suitable level conversion |
| Red LED | D6 through 220Ω resistor |
| Green LED | D7 through 220Ω resistor |

The ESP-01 must have a stable 3.3V supply capable of handling Wi-Fi current peaks. Do not power it from an inadequate Uno 3.3V output. Confirm the actual ESP-01 pinout before wiring.

## Operation

1. The Uno reads the soil sensor analog output at A0.
2. The example calibration maps raw ADC 1023 to 0% (dry) and 300 to 100% (wet). Calibrate these endpoints for the actual sensor and soil.
3. Below 30% moisture, the red LED turns on and the green LED turns off.
4. At or above 30%, the green LED turns on and the red LED turns off.
5. The ESP-01 connects to Wi-Fi using AT commands and uploads moisture as ThingSpeak Field 1.
6. The example samples and attempts an upload every 20 seconds, matching the handbook code.

## Configure and build

1. Copy `include/config.example.h` to `include/config.h`.
2. Enter Wi-Fi SSID, Wi-Fi password and ThingSpeak Write API Key in the local file.
3. Keep `config.h` private; it is ignored by Git.
4. Build with PlatformIO:

```bash
pio run -e uno
```

Upload using:

```bash
pio run -e uno -t upload
pio device monitor -b 9600
```

Create a ThingSpeak channel with Field 1 named `Soil Moisture (%)`. Use the channel's Write API Key in the local config.

## Calibration and limitations

The 1023/300 endpoints are handbook example values, not universal sensor calibration constants. Record dry-air and wet-soil readings for the exact sensor and adjust the mapping. The red/green threshold is 30%, as shown in the handbook example. The code uses plain HTTP over the ESP-01 AT TCP connection as in the handbook example; use only for this educational prototype and do not transmit sensitive information.

## Verification status

The repository contains firmware and hosted build configuration. Physical sensor calibration, LED operation, ESP-01 Wi-Fi association and live ThingSpeak upload must be tested on the actual hardware before they can be reported as passed. No physical test is claimed by this repository.
