# Filename: simple-function-object.py

def hello(who):
    print 'Hello', who

def goodbye(who):
    print 'Goodbye', who

funclist = [hello, goodbye]

# Some time later
for func in funclist:
    func('Hugo')
