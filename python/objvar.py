# Filename: objvar.py

class Robot:
    ''' Represents a robot, with a name.'''

    population = 0

    def __init__(self, name):
        '''Initialize the data.'''
        self.name = name
        print('(Initializing {0})'.format(self.name))

        Robot.population += 1

    def __del__(self):
        '''I am dying'''
        print('{0} is being destroyed'.format(self.name))

        Robot.population -= 1

        if Robot.population == 0:
            print('{0} was the last one.'.format(self.name))
        else:
            print('There are still {0:d} robots working'.format(Robot.population))

    def sayHi(self):
        '''Greeting by the robot.

        Yeah, they can do that.'''
        print('Greetings, my masters call me {0}'.format(self.name))

    def howMany():
        '''Prints the current population'''
        print('We have {0:d} robots'.format(Robot.population))
    howMany = staticmethod(howMany)


r1 = Robot('R2-D2')
r1.sayHi()
Robot.howMany()

r2 = Robot('C-3P0')
r2.sayHi()
Robot.howMany()

print("\nRobots can do some work here.\n")

print("Robots have finished their work.So let's destroy them.")
del r1
del r2

Robot.howMany()
        
