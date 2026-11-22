import csv
import math
import unittest
from pathlib import Path

CSV_PATH = Path(__file__).resolve().parents[1] / "examples" / "sample_readings.csv"


class SoilMoistureSampleTests(unittest.TestCase):
    def setUp(self):
        with CSV_PATH.open(newline="", encoding="utf-8") as handle:
            self.rows = list(csv.DictReader(handle))

    def test_schema_and_illustrative_label(self):
        self.assertGreater(len(self.rows), 0)
        self.assertEqual(
            set(self.rows[0]),
            {"timestamp", "soil_moisture_percent", "record_type"},
        )
        self.assertTrue(all(row["record_type"] == "illustrative" for row in self.rows))

    def test_moisture_is_numeric_and_in_range(self):
        for row in self.rows:
            moisture = float(row["soil_moisture_percent"])
            self.assertTrue(math.isfinite(moisture))
            self.assertGreaterEqual(moisture, 0.0)
            self.assertLessEqual(moisture, 100.0)


if __name__ == "__main__":
    unittest.main()
