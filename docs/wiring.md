# Project 06 — Wiring and Interfaces
| Device signal | Arduino Uno |
|---|---|
| ACS712 VCC / GND / OUT | 5V / GND / A1 |
| LCD SDA / SCL | A4 / A5 |
| ESP-01 TX | D10 (SoftwareSerial RX) |
| ESP-01 RX | D11 (SoftwareSerial TX) through 5V-to-3.3V level conversion |

ESP-01 VCC and EN/CH_PD require a stable, adequate 3.3V supply. Confirm the exact module pinout, current requirements and AT firmware baud rate. Firmware defaults to 9600 baud. ThingSpeak fields: Field 1 current RMS in amperes; Field 2 estimated apparent power in VA.

**Mains warning:** This table covers low-voltage signal interfaces only. The ACS712 current path must be installed in an appropriately enclosed, fused and insulated fixture by a qualified electrician. Never put mains on a breadboard or connect mains to Uno/ESP pins.
