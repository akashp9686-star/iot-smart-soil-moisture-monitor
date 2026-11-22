# Repository Review Checklist

## Repository contents
- [x] README and project abstract
- [x] Architecture and component inventory
- [x] Firmware source and PlatformIO configuration
- [x] Safe example configuration with no credentials
- [x] Wiring interface notes and separate mains safety guidance
- [x] Methodology, research references and limitations
- [x] MQTT setup guide
- [x] Illustrative CSV and Python tests
- [x] GitHub Actions workflow

## Software verification
- [x] Latest confirmed successful GitHub Actions firmware build passes (run #13)
- [x] MQTT-disabled firmware compilation passes
- [x] MQTT-enabled firmware compilation passes
- [x] Sample-data unit tests pass (2 tests)

## Physical validation (not claimed by this repository package)
- [ ] Confirm exact PZEM revision and hardware compatibility
- [ ] Qualified mains installation and inspection
- [ ] UART communication test
- [ ] Reference-instrument comparison
- [ ] MQTT delivery test, if enabled
- [ ] Genuine evidence and completed results record

A checked repository-content or software-verification item means the corresponding file is included or the stated automated check passed. It does not mean the hardware has been assembled, tested or certified.
