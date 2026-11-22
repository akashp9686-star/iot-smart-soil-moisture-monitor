# Project 06 — Smart Home Energy Meter
**Glowlogics IoT Projects Handbook | HARD | Arduino Uno + ACS712 + ESP8266 ESP-01 + ThingSpeak**

This repository follows handbook Project 06: Arduino Uno samples an ACS712-20A current sensor, estimates RMS current and apparent power, displays readings on a 16x2 I2C LCD, and uses an ESP8266 ESP-01 in AT-command mode to upload to ThingSpeak.

**Verification status:** Source and documentation are prepared. Physical sensor operation, calibration, mains installation, ESP-01 Wi-Fi association, LCD operation and ThingSpeak upload have not been claimed as completed.

## Required hardware (handbook)
Arduino Uno R3 (1); ACS712-20A module (1); ESP8266 ESP-01 (1); logic-level converter (1); 16x2 LCD with I2C module (1); 220 V extension cord / enclosed test fixture (qualified-person installation only); 10 uF capacitor; jumper wires and breadboard for low-voltage prototyping.

## Pin mapping
- ACS712 VCC/GND/OUT -> Uno 5V/GND/A1.
- LCD SDA/SCL -> Uno A4/A5.
- ESP-01 TX -> Uno D10 (SoftwareSerial RX).
- Uno D11 (SoftwareSerial TX) -> ESP-01 RX through 5V-to-3.3V level conversion.
- ESP-01 VCC and CH_PD/EN -> suitable regulated 3.3V supply; common low-voltage ground.

Verify the exact ESP-01 pinout and supply capability. Do not power the ESP-01 from an inadequate 3.3V source.

## Software and data
Arduino framework; LiquidCrystal_I2C library; SoftwareSerial; ESP-01 AT firmware. ThingSpeak Field 1 = RMS current (A), Field 2 = apparent power (VA). Configure WIFI_SSID, WIFI_PASSWORD and THINGSPEAK_WRITE_API_KEY privately; never commit credentials. ESP-01 AT baud is set to 9600 and must match the module.

## Method and limitations
Current RMS is estimated from ADC sample variance over a one-second window. ACS712-20A nominal sensitivity is assumed to be 100 mV/A; verify module variant and calibrate. Apparent power is estimated as current multiplied by assumed nominal 230 V. This is not true active power because voltage waveform and power factor are not measured. Sensor offset, noise, ADC reference and sampling affect accuracy. Upload interval is 30 seconds.

## Build
Firmware: src/main.cpp. PlatformIO target: env:uno. Alternatively compile in Arduino IDE after installing the LiquidCrystal_I2C library and selecting Arduino Uno.

## Safety
**Mains voltage can kill.** Mains-side ACS712 installation, enclosure, fusing, insulation, earthing and inspection must be designed and performed by a qualified electrician. Never route mains through a breadboard or expose live conductors. Never connect mains to Arduino/ESP GPIO. Keep low-voltage circuitry safely isolated.

## Evaluation status
This is a repository-based implementation and plan. Physical readings, calibration, mains installation and live ThingSpeak transmission remain pending until performed and documented.