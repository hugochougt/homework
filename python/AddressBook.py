# A command-line address-book program

class Contact:
        
    def __init__(self):
        print('Enter name: ')
        self.name = input()
        print('Enter email address: ')
        self.emailAddress = input()
        print('Enter phone number: ')
        self.phoneNumber = input()
        Contact.save(self)
        print('Add {0} successfully.'.format(self.name))

    def save(self):
        f = open('Address-book.txt', 'a')
        f.write('Name: {0}\n'.format(self.name))
        f.write('Email address: {0}\n'.format(self.emailAddress))
        f.write('Phone number: {0}\n'.format(self.phoneNumber))
        f.write('\n')
        f.close()

    @staticmethod
    def browse():
        with open('Address-book.txt') as f:
            for line in f:
                print(line, end='')

    @staticmethod
    def add():
        Contact()

    @staticmethod
    def search(name):
        with open("Address-book.txt") as f:
            for line in f:
                if line.find(name) != -1:
                    print(line, end='')
                    print(f.readline(), end='')
                    print(f.readline(), end='')
                    break
            else:
                print(name,' is not in the address-book.')

    @staticmethod
    def delete(name):
        print("Contact information below is being deleting...")
        # Contact.search(name)
        content = []
        with open("Address-book.txt") as f:
            for line in f:
                if line.find(name) != -1:
                    print(line, end='')
                    print(f.readline(), end='')
                    print(f.readline(), end='')
                    f.readline()
                else:
                    content.append(line)
                    # print(content)
        f = open("Address-book.txt", 'w')
        for item in content:
            f.write(item)
        f.close()
        print('Successfully delete')

    __version__ = '0.1'
            
