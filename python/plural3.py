import re

def build_match_and_apply_functions(pattern, search, replace):
	def match_rule(word):
		return re.search(pattern, word)
	def apply_rule(word):
		return re.sub(earch, repleace, word)
	return  (match_rule, apply_rule)
	
patterns = \
(
	('[sxz]$',				'$', 'es'),
	('[^aeioudgkprt]h$',	'$', 'es'),
	('(qu|[^aeiou])y$',		'$', 'es'),
	('$',					'$', 'es')
)

rules = [build_match_and_apply_functions(pattern, search, replace)
		for (pattern, search, replace) in patterns]