# Testing and Verification Record

## Automated repository checks

The latest recorded GitHub Actions run [#10](https://github.com/akashp9686-star/smart-home-energy-meter/actions/runs/45000141024) completed successfully on 22 November 2026.

| Check | Method | Result |
|---|---|---|
| Firmware compilation, MQTT disabled | GitHub Actions / PlatformIO | Passed |
| Firmware compilation, MQTT enabled | GitHub Actions / PlatformIO | Passed |
| CSV schema and illustrative-data checks | Python unit tests | Passed — 2 tests |

The workflow installs PlatformIO, creates a local config from `include/config.example.h`, compiles both firmware configurations and runs the Python tests. This is hosted software verification for the configured PlatformIO target.

## Physical and integration checks

| Check | Method | Status |
|---|---|---|
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

**Interpretation:** A passing CI run proves that the source compiles for the selected target and that the included sample-data checks pass. It does not prove physical sensor operation, measurement accuracy, electrical safety, calibration or live MQTT delivery.
