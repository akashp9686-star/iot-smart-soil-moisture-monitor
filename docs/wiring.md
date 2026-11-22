# Wiring — Glowlogics Project 03

| Handbook signal | Arduino Uno R3 |
|---|---|
| Soil sensor VCC | 5V |
| Soil sensor GND | GND |
| Soil sensor AO | A0 |
| ESP-01 VCC + CH_PD/EN | Regulated 3.3V (common ground) |
| ESP-01 GND | Arduino GND |
| ESP-01 TX → Uno RX | D10 through suitable level conversion as specified by the handbook |
| Uno TX → ESP-01 RX | D11 through 5V-to-3.3V level conversion |
| Red LED | D6 through 220Ω resistor |
| Green LED | D7 through 220Ω resistor |

Use a stable 3.3V regulator/supply for ESP-01 Wi-Fi current peaks. Confirm the ESP-01 board's pinout and UART logic levels before wiring. Never connect Uno 5V TX directly to ESP-01 RX.

## Calibration
The handbook example maps ADC raw 1023 to dry (0%) and 300 to wet (100%). Calibrate these endpoints using the actual sensor and soil. The handbook example declares dry when moisture is below 30%.
