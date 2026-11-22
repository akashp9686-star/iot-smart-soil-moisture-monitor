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
            {"timestamp", "current_rms_a", "estimated_apparent_power_va", "record_type"},
        )
        self.assertTrue(all(row["record_type"] == "illustrative" for row in self.rows))

    def test_estimates_are_numeric_and_nonnegative(self):
        for row in self.rows:
            current = float(row["current_rms_a"])
            apparent = float(row["estimated_apparent_power_va"])
            self.assertTrue(math.isfinite(current))
            self.assertTrue(math.isfinite(apparent))
            self.assertGreaterEqual(current, 0.0)
            self.assertLessEqual(current, 20.0)
            self.assertGreaterEqual(apparent, 0.0)
            self.assertLessEqual(apparent, 4600.0)


if __name__ == "__main__":
    unittest.main()
