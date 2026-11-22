# Telemetry Data Format

When MQTT is enabled and the client is connected, the firmware publishes a JSON object to the topic configured by `MQTT_TOPIC`.

| Key | Unit | Meaning |
|---|---|---|
| `device` | text | Configured device identifier |
| `uptime_ms` | milliseconds | ESP32 uptime at publication |
| `voltage_v` | volts | RMS voltage value returned by the PZEM library |
| `current_a` | amperes | Current value returned by the PZEM library |
| `power_w` | watts | Active power value returned by the PZEM library |
| `energy_kwh` | kilowatt-hours | Accumulated energy value returned by the PZEM library |
| `frequency_hz` | hertz | Frequency value returned by the PZEM library |
| `power_factor` | unitless | Power factor returned by the PZEM library |

Example payload shape (illustrative only):

```json
{
  "device": "energy-meter-01",
  "uptime_ms": 15000,
  "voltage_v": 230.0,
  "current_a": 0.42,
  "power_w": 85.0,
  "energy_kwh": 1.201,
  "frequency_hz": 50.0,
  "power_factor": 0.88
}
```

The example values are not measurements from a physical device. Consumers should validate incoming fields, timestamps/uptime, device identity and acceptable operating ranges.
