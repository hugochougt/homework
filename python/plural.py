import re

def plural(noun):
	if re.search('[sxz]$', noun):	# 中括号表示“匹配这些字符的其中之一”
		return re.sub('$', 'es', noun)	# 该 re.sub() 函数执行基于正则表达式的字符串替换。
	elif re.search('[^aeioudgkprt]h$', noun):
		return re.sub('$', 'es', noun)
	elif re.search('[^aeiou]y$', noun):
		return re.sub('y$', 'ies', noun)
	else:
		return noun + 's'
		