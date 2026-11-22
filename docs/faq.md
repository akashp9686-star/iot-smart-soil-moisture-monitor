# Frequently Asked Questions

## Does the repository include a physical project?
No. It is a repository-first firmware and documentation submission. It does not claim a physical assembly or demonstration.

## Has the firmware been compiled?
Yes. GitHub Actions successfully compiled the ESP32 firmware for the configured PlatformIO environment.

## Were the sample readings collected from a sensor?
No. The CSV values are labelled illustrative and are used only to validate the sample-data format and broad numeric ranges.

## Is MQTT required?
No. MQTT is disabled by default. It can be enabled with local credentials in the ignored config file.

## Can I connect the PZEM module directly without checking its revision?
No. Confirm the exact module revision, terminal arrangement, interface requirements and datasheet first. Mains-side installation must be completed by a qualified electrician.

## Does a passing build mean the energy readings are accurate?
No. Accuracy requires physical testing and comparison with a suitable reference instrument under controlled conditions.
