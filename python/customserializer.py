
def to_json(python_object):
	if isinstance(python_object, bytes):
		return {'__class__':'bytes',
				'__value__':list(python_object)}
	raise TypeError(repr(python_object) + ' is not JSON serializable')