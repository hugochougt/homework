# Filename: raising.py

class ShortInputException(Exception):
    '''A user-defined exception class.'''
    def __init__(self, length, atleast):
        Exception.__init__(self)
        self.length = length
        self.atleast = atleast

try:
    text = input('Enter something --> ')
    if len(text) < 5:
        raise ShortInputException(len(text), 5)
except EOFError:
    print('Why did you do an EOF on me?')
except ShortInputException as ex:
    print('ShortInputException: The input was {0} long, expected at least {1}.'\
          .format(len(text), 5))
else:
    print('No exception was raised.')
