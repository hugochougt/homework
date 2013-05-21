# Filename: class_init.py

class Person:
    def __init__(self, name):
       self.name = name

    def sayHi(self):
        print('Hi, my name is', self.name)

p = Person('Hugo')
p.sayHi()
