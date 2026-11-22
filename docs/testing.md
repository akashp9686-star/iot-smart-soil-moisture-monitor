# Testing and Verification Plan

## Automated repository checks
GitHub Actions is configured to:
- install PlatformIO,
- create a local config file from `include/config.example.h`,
- compile the ESP32 firmware with `pio run`,
- run Python unit tests against the illustrative CSV sample.

The workflow result is the evidence for the hosted build. Do not mark it passed until the actual GitHub Actions run completes successfully.

## Software checks

| Check | Method | Status |
|---|---|---|
| Firmware compilation | GitHub Actions / PlatformIO | Pending until workflow passes |
| CSV schema and numeric bounds | Python unit tests | Pending until workflow passes |
| PZEM communication | Physical module and serial output | Not performed |
| Meter accuracy | Comparison with calibrated reference meter | Not performed |
| Wi-Fi connection | Physical ESP32 and network | Not performed |
| MQTT publish/subscribe | Actual broker and client | Not performed |
| Mains installation safety | Qualified professional inspection | Not performed |

## Physical verification procedure
Only a qualified person should perform mains-side installation and checks. Record the exact module revision, board, installation method, date, reference instrument and operating conditions. Never fabricate measurements or photographs.

- [ ] Confirm exact PZEM module model/revision and datasheet.
- [ ] Have mains-side installation completed and inspected by a qualified electrician.
- [ ] Confirm UART communication on the safely installed setup.
- [ ] Compare readings with a suitable reference instrument.
- [ ] Verify MQTT delivery if enabled.
- [ ] Record actual results and limitations.
