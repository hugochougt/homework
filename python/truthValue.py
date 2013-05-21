# p108 Computer Projects 1

p = int(input('Input the truth value of p : '))
q = int(input('Input the truth value of q : '))

def conjunction(p, q):
	if p == 1 and q == 1:
		print('The truth value of conjunction of p & q is : true')
	else:
		print('The truth value of conjunction of p & q is : false')
		
def disjunction(p, q):
	if p == 1 or q == 1:
		print('The truth value of disjunction of p & q is : true')
	else:
		print('The truth value of disjunction of p & q is : false')
		
def exclusiveOr(p, q):
	if p != q:
		print('The truth value of exclusive or of p & q is : true')
	else:
		print('The truth value of exclusive or of p & q is : false')
		
def condictionStatement(p, q):
	if p == 1 and q == 0:
		print('The truth value of condiction statement of p & q is : false')
	else:
		print('The truth value of condiction statement of p & q is : true')
		
def biconditional(p, q):
	if p == q:
		print('The truth value of conditional of p & q is : true')
	else:
		print('The truth value of conditional of p & q is : false')
		
conjunction(p, q)
disjunction(p, q)
exclusiveOr(p, q)
condictionStatement(p, q)
biconditional(p, q)