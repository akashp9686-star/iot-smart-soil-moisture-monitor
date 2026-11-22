# Technical Research — Glowlogics Project 06

## Arduino Uno and ADC
The project uses an Arduino Uno analog input (A1) to sample the ACS712-20A sensor output. The ADC reference and sensor offset influence calculated current. Calibration must use the exact module revision and a suitable reference instrument.

Reference: https://docs.arduino.cc/hardware/uno-rev3/

## ACS712 current sensor
The ACS712 family uses a Hall-effect current sensor with analog output. Sensitivity differs by current-range variant; the firmware's nominal 100mV/A assumption must be confirmed for the 20A module actually used. Offset drift, noise and sampling window affect RMS estimates.

Reference: https://www.allegromicro.com/en/products/sense/current-sensor-ics/integrated-current-sensors/acs712

## ESP8266 ESP-01 AT interface
The ESP-01 provides Wi-Fi through AT commands over UART. The Uno's 5V TX signal must be reduced to a safe ESP-01 RX logic level using a suitable level converter. Provide a stable regulated 3.3V supply with sufficient current capability. Firmware expects 9600 baud; confirm the module's installed AT firmware.

Reference: https://docs.espressif.com/projects/esp-at/en/latest/

## ThingSpeak telemetry
The firmware sends Field 1 = estimated RMS current (A) and Field 2 = estimated apparent power (VA). Apparent power is calculated using assumed nominal 230V; this is not active power because voltage waveform and power factor are not measured. The upload interval is 30 seconds.

Reference: https://www.mathworks.com/help/thingspeak/

## I2C LCD
The 16x2 LCD uses an I2C backpack connected to Uno SDA (A4) and SCL (A5). Backpack addresses vary; firmware's configured address must be checked against the actual module.

## Capacitor and safety
The handbook component list includes a 10µF capacitor. Confirm its exact placement and polarity against the actual ACS712 module schematic; do not infer a circuit connection from the component list alone. Mains-side installation and enclosure must be designed and performed by a qualified electrician.

## Verification boundary
These references explain the chosen components and interfaces. They do not establish that the physical system has been assembled, calibrated or tested. CI compilation and illustrative sample-data checks are software-only evidence.
