import csv
import math
import unittest
from pathlib import Path

CSV_PATH = Path(__file__).resolve().parents[1] / "examples" / "sample_readings.csv"


class SampleReadingsTests(unittest.TestCase):
    def setUp(self):
        with CSV_PATH.open(newline="", encoding="utf-8") as handle:
            self.rows = list(csv.DictReader(handle))

    def test_schema_and_illustrative_label(self):
        self.assertGreater(len(self.rows), 0)
        self.assertEqual(
            set(self.rows[0]),
            {
                "timestamp", "voltage_v", "current_a", "power_w",
                "energy_kwh", "frequency_hz", "power_factor", "record_type"
            },
        )
        self.assertTrue(all(row["record_type"] == "illustrative" for row in self.rows))

    def test_measurements_are_numeric_and_in_broad_ranges(self):
        for row in self.rows:
            values = {key: float(row[key]) for key in (
                "voltage_v", "current_a", "power_w", "energy_kwh",
                "frequency_hz", "power_factor"
            )}
            self.assertTrue(all(math.isfinite(value) for value in values.values()))
            self.assertGreaterEqual(values["voltage_v"], 0.0)
            self.assertLessEqual(values["voltage_v"], 300.0)
            self.assertGreaterEqual(values["current_a"], 0.0)
            self.assertLessEqual(values["current_a"], 100.0)
            self.assertGreaterEqual(values["power_w"], 0.0)
            self.assertLessEqual(values["power_w"], 30000.0)
            self.assertGreaterEqual(values["energy_kwh"], 0.0)
            self.assertGreaterEqual(values["frequency_hz"], 0.0)
            self.assertLessEqual(values["frequency_hz"], 100.0)
            self.assertGreaterEqual(values["power_factor"], 0.0)
            self.assertLessEqual(values["power_factor"], 1.0)


if __name__ == "__main__":
    unittest.main()
