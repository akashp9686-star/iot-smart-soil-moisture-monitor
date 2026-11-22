# ThingSpeak Data Format — Project 06

The firmware writes two fields to ThingSpeak using the ESP-01 AT-command connection.

| ThingSpeak field | Unit | Meaning |
|---|---|---|
| Field 1 | A | Estimated RMS current |
| Field 2 | VA | Estimated apparent power (RMS current × assumed nominal 230V) |

Illustrative example only:
```text
field1=0.420
field2=96.6
```

These are not measured readings. The firmware does not sample voltage waveform or power factor; Field 2 is not true active power in watts and must not be presented as such. Upload interval is configured to 30 seconds.