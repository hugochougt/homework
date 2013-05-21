import unittest

class ToRomanBadInput(unittest.TestCase):
	def test_too_large(self):
		'''to_roman should fail with large input'''
		self.assertRaise(roman2.OutOfRangeError, roman2.to_roman, 4000)