# Frequently Asked Questions — Project 06

## Which hardware does this repository target?
Arduino Uno, ACS712-20A, ESP8266 ESP-01, logic-level conversion, 16x2 I2C LCD and ThingSpeak.

## What is measured?
The firmware estimates RMS current. Apparent power is estimated as current × assumed 230V. It does not measure voltage waveform or power factor and therefore does not calculate true active power.

## Has the hardware been tested?
No physical sensor calibration, LCD test, ESP-01 Wi-Fi association, ThingSpeak upload or mains installation is claimed as completed.

## Why is a 10µF capacitor listed?
It appears in the handbook component list. Confirm its exact placement, voltage rating and polarity against the actual ACS712 module documentation before assembly.

## Is mains wiring safe to build on a breadboard?
No. Mains-side installation must be enclosed, protected and completed by a qualified electrician.