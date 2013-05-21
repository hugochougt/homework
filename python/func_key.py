def func(a, b = 38, c = 99):
	print('a is {0}, b is {1}, c is {2}'.format(a, b, c))
	
func(3, 7)
func(23, c = 24)
func(c = 12, a = 100)