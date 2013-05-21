class OutOfRangeError(ValueError):
	def to_roman(n):
		'''convert integer to Roman numeral'''
		if n > 3999:
			raise OutOfRangeError('number out of range (must be less than 4000)')

		result = ''
		for numeral, integer in roman_numeral_map:
			while n >= integer:
				result += numeral
				n -= integer
		return result