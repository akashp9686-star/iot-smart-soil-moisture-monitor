# Project 06 — Wiring and Interfaces
| Device signal | Arduino Uno |
|---|---|
| ACS712 VCC / GND / OUT | 5V / GND / A1 |
| LCD SDA / SCL | A4 / A5 |
| ESP-01 TX | D10 (SoftwareSerial RX) |
| ESP-01 RX | D11 (SoftwareSerial TX) through 5V-to-3.3V level conversion |

ESP-01 VCC and EN/CH_PD require a stable, adequate 3.3V supply. Confirm exact module pinout, current requirements and AT firmware baud rate (firmware default 9600 baud).

## Handbook 10µF capacitor
The handbook lists a 10µF capacitor as a filter capacitor on the ACS712 output. The exact capacitor terminal placement/polarity is not fully specified in the text wiring table. Verify the sensor board schematic and capacitor voltage/polarity ratings before installation; do not invent a connection from this guide alone.

ThingSpeak Field 1 = RMS current (A); Field 2 = estimated apparent power (VA).

**Mains warning:** This table covers low-voltage signal interfaces only. The ACS712 current path must be installed in an appropriately enclosed, fused and insulated fixture by a qualified electrician. Never put mains on a breadboard or connect mains to Uno/ESP pins.
