# Project 06 — Smart Home Energy Meter
**Glowlogics IoT Projects Handbook | HARD | Arduino Uno + ACS712-20A + ESP8266 ESP-01 + 16x2 I2C LCD + ThingSpeak**

This repository implements the handbook architecture: Uno samples ACS712 current, estimates RMS current and apparent power, displays readings locally, and uses ESP-01 AT commands to upload two fields to ThingSpeak.

## Hardware and pin map
- Arduino Uno R3 (1)
- ACS712-20A: VCC/GND/OUT -> 5V/GND/A1
- ESP8266 ESP-01 (1), AT firmware at 9600 baud
- Logic-level converter (1): Uno D11 TX -> ESP-01 RX; ESP-01 TX -> Uno D10 RX
- ESP-01 stable regulated 3.3V supply, EN/CH_PD enabled, common low-voltage ground
- 16x2 LCD + I2C: SDA A4, SCL A5
- 10µF capacitor listed by handbook; verify exact placement/polarity against actual module schematic before fitting
- Low-voltage breadboard/jumpers; mains fixture by qualified electrician only

## ThingSpeak mapping
Field 1 = estimated RMS current (A). Field 2 = estimated apparent power (VA). Apparent power is current × assumed 220V; it is not active power because voltage waveform and power factor are not measured. Upload interval: 30 seconds.

## Configure and build
Copy `include/config.example.h` to `include/config.h`, enter private Wi-Fi and ThingSpeak credentials, then run:
```bash
pio run -e uno
pio run -e uno -t upload
pio device monitor -b 9600
```
Never commit `config.h` or credentials.

## Measurement limitations
ACS712 sensitivity, offset, ADC reference and sampling require calibration against a suitable reference. The 220V apparent-power estimate is not billing-grade energy or active power.

## Safety
Mains voltage can kill. A qualified electrician must design, install and inspect the mains-side current path, enclosure, fusing, insulation and earthing. Never route mains through a breadboard or connect it to Arduino/ESP pins.

## Verification
Check latest GitHub Actions for hosted Uno compilation and sample-data tests. Physical ACS712 calibration, LCD, ESP-01 Wi-Fi, live ThingSpeak and mains installation remain unverified. Example CSV is illustrative only.
