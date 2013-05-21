# Filename: lambda.py

def makeRepeater(n):
    return lambda s: s * n

twice = makeRepeater(2)

print(twice('word '))
print(twice(5))
