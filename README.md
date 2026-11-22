# Project 06 — Smart Home Energy Meter
**Glowlogics IoT Projects Handbook | HARD | Arduino Uno + ACS712-20A + ESP8266 ESP-01 + ThingSpeak**

This repository implements the handbook's Project 06 architecture: the Uno samples an ACS712-20A current sensor, estimates RMS current and apparent power, displays values on a 16x2 I2C LCD, and sends readings to ThingSpeak through an ESP-01 using AT commands.

## Handbook component checklist
| Component | Quantity | Repository treatment |
|---|---:|---|
| Arduino Uno R3 | 1 | Firmware target |
| ACS712-20A module | 1 | Current input at A1 |
| ESP8266 ESP-01 | 1 | AT-command Wi-Fi module |
| Logic-level converter | 1 | Uno TX to ESP-01 RX |
| 16x2 LCD + I2C module | 1 | Local display |
| 220V extension cord / safe fixture | 1 | Mains-side fixture only; qualified electrician |
| 10µF capacitor | 1 | Handbook specifies filtering at ACS712 output; verify polarity, voltage rating and exact placement against the sensor/module documentation before fitting |
| Jumper wires and breadboard | — | Low-voltage prototyping only |

## Wiring
- ACS712 VCC/GND/OUT -> Uno 5V/GND/A1.
- LCD SDA/SCL -> Uno A4/A5.
- ESP-01 TX -> Uno D10 (SoftwareSerial RX).
- Uno D11 (SoftwareSerial TX) -> ESP-01 RX through 5V-to-3.3V level conversion.
- ESP-01 VCC and CH_PD/EN -> stable regulated 3.3V supply; common ground.
- The 10µF filter capacitor is a handbook component; do not guess its connection or polarity. Follow the exact ACS712 board documentation and observe capacitor voltage/polarity ratings.

## Firmware and cloud fields
PlatformIO target: `env:uno`. Libraries: LiquidCrystal_I2C and Arduino core (SoftwareSerial is included with AVR core). ESP-01 AT baud is configured at 9600 and must match the module.
- ThingSpeak Field 1: RMS current (A).
- ThingSpeak Field 2: estimated apparent power (VA).
- Upload interval: 30 seconds.
Configure `WIFI_SSID`, `WIFI_PASSWORD`, and `THINGSPEAK_WRITE_API_KEY` privately through build flags or local configuration; never commit credentials.

## Calculation and limitations
Firmware estimates RMS current from ADC sample variance over a one-second window, using nominal ACS712-20A sensitivity of 100 mV/A. Confirm the exact sensor variant and calibrate against a suitable reference instrument. Apparent power is estimated as current × assumed 230 V. It is **not true active power**: voltage waveform and power factor are not measured. ADC reference, sensor offset, noise, sampling and calibration affect accuracy.

## Build
```bash
pio run -e uno
pio run -e uno -t upload
pio device monitor -b 9600
```

## Safety
**Mains voltage can kill.** A qualified electrician must design, install and inspect the mains-side current path, enclosure, fusing, insulation, earthing and strain relief. Never place mains on a breadboard, expose live conductors, or connect mains to Arduino/ESP GPIO. Keep all MCU wiring safely isolated.

## Verification
The repository is source/documentation, not proof of completed hardware testing. ACS712 calibration, LCD operation, ESP-01 AT/Wi-Fi association and live ThingSpeak upload remain pending until performed and documented. CI compilation, if green, proves compilation only.
