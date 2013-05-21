x = 50

def fun():
	global x
	print('x is ', x)
	x = 3
	print('Changed global x to', x)
	
fun()
print('x is ', x)