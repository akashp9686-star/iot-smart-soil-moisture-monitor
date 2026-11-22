# Limitations and Known Risks — Project 06

- Firmware targets Arduino Uno + ACS712-20A + ESP-01 AT + I2C LCD + ThingSpeak, not ESP32/PZEM/MQTT.
- RMS current estimate depends on sensor offset, sensitivity, ADC reference, sample timing and calibration.
- Apparent power uses an assumed nominal 230V and is not measured active power; voltage waveform and power factor are not sampled.
- ESP-01 AT firmware version and baud must match configuration; stable regulated 3.3V supply is required.
- LCD I2C address may vary by backpack.
- 10µF capacitor placement must be checked against the exact sensor/module schematic.
- Example data is illustrative, not measured.
- Physical calibration, display, Wi-Fi and ThingSpeak tests remain pending.
- Mains isolation, enclosure, fusing and regulatory compliance are not established by a successful software build.