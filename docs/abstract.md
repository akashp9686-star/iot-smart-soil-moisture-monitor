# Abstract

The Smart Home Energy Meter repository describes an ESP32-based energy monitoring node using a PZEM-004T v3 metering module. The module provides electrical measurements over a serial interface; the ESP32 reads and validates the data, displays it on the serial monitor, and can optionally publish telemetry through MQTT.

The package includes firmware source, reproducible build configuration, example data, automated sample-data checks, system design notes, safety boundaries and a verification plan. Physical installation, calibration and live telemetry have not been performed as part of this repository preparation.
