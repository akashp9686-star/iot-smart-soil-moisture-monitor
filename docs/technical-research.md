# Technical Notes and References — Project 03

## Arduino Uno analog input
The Uno reads the sensor's analog output on A0. The 10-bit ADC provides nominal readings from 0 to 1023. Actual values depend on sensor construction, supply voltage, soil composition and moisture.

Reference: https://docs.arduino.cc/hardware/uno-rev3/

## Soil moisture sensing
The handbook permits a capacitive or resistive analog-output soil moisture sensor. The provided example maps raw ADC 1023 to dry and 300 to wet; these are starting values only and must be calibrated for the exact sensor. Capacitive sensors are generally preferred for longer-term soil exposure because exposed resistive electrodes can corrode, but the handbook allows either type.

## ESP8266 ESP-01 AT interface
The ESP-01 communicates with the Uno over UART using AT commands. The handbook assigns Uno D10/D11 to the serial interface and requires a logic-level converter. ESP-01 power must be a stable regulated 3.3V supply; verify the module's installed AT firmware and baud rate.

Reference: https://docs.espressif.com/projects/esp-at/en/latest/

## ThingSpeak
The Uno sends the measured moisture percentage as Field 1 using the ESP-01's TCP connection to api.thingspeak.com. The example interval is 20 seconds.

Reference: https://www.mathworks.com/help/thingspeak/

## Scope boundary
These notes describe the design and calibration requirements; they are not evidence of a completed physical build. Record actual module revisions, calibration values, serial logs and ThingSpeak observations during testing.
