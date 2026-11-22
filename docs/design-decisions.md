# Design Decisions — Project 06

## Arduino Uno target
The PlatformIO environment targets Arduino Uno (ATmega328P), matching the handbook controller.

## ACS712 current sensing
The firmware samples ACS712-20A analog output on A1 and calculates RMS current from 1,000 samples, using a 2.5V midpoint offset and 200µs sample spacing. The assumed sensitivity is nominal; exact module variant and calibration must be verified.

## ESP-01 AT interface
SoftwareSerial uses Uno D10 as RX and D11 as TX. Uno TX is level-converted before the ESP-01 RX pin. ESP-01 requires a stable regulated 3.3V supply and compatible AT firmware baud (default 9600).

## ThingSpeak fields
Field 1 contains estimated RMS current (A). Field 2 contains estimated apparent power (VA), calculated using assumed 220V. It is not active power.

## Local credentials
Wi-Fi SSID/password and ThingSpeak Write API key are supplied privately and must never be committed.

## Safety and verification
Mains-side work belongs to a qualified electrician. Example readings are illustrative; CI compilation does not prove sensor calibration, electrical safety or cloud delivery.