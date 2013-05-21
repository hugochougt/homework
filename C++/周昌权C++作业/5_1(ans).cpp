#include <iostream>
#include <string>
using namespace std;

class Mammal {
 string color;
 string weight;
 static int count;
 
 public:
 Mammal (string c, string w) : color(c), weight(w) { count++; }
 virtual ~Mammal () { count--; }
 virtual void print() { 
     cout << "Mammal::color: " << color << endl
             << "Mammal::weight: " << weight << endl;
 }
 static void printCount() { cout << "Mammal::count: "<< count << endl; }
};

class Dog : public Mammal {
 string color;
 string weight;
 static int count;
 
 public:
    Dog(string c, string w) : color(c),weight(w), Mammal(c,w){ count++; }
 virtual ~Dog() { count--; }
    void print() { 
     cout << "Dog::color: " << color << endl
             << "Dog::weight: " << weight << endl;
 }
 static void printCount() { cout << "Dog::count: "<< count << endl; }
};

class Cat : public Mammal {
 string color;
 string weight;
 static int count;
 
 public:
    Cat(string c, string w) : color(c),weight(w), Mammal(c,w){ count++; }
 virtual ~Cat() { count--; }
    void print() { 
     cout << "Cat::color: " << color << endl
             << "Cat::weight: " << weight << endl;
 }
 static void printCount() { cout << "Cat::count: "<< count << endl; }
};

int Mammal::count = 0;
int Dog::count = 0;
int Cat::count = 0;

int main() {
 Mammal m1("red","15");
 m1.print();
 Mammal::printCount();
 Dog::printCount();
 Cat::printCount();
 cout << endl;
 
 Mammal m2 ("blue", "20");
 m2.print();
 Mammal::printCount();
 Dog::printCount();
 Cat::printCount();
 cout << endl;
 
 Dog d1("black", "10");
 d1.print();
 Mammal::printCount();
 Dog::printCount();
 Cat::printCount();
 cout << endl;
 
 Cat c1("white", "8");
 c1.print();
 Mammal::printCount();
 Dog::printCount();
 Cat::printCount();
 cout << endl;
 
 Mammal* pm = new Mammal("yellow", "50");
 pm->print();
 Mammal::printCount();
 Dog::printCount();
 Cat::printCount();
 cout << endl;
 
 Mammal* pd = new Dog("white", "15");
 pd->print();
 Mammal::printCount();
 Dog::printCount();
 Cat::printCount();
 cout << endl;
 
 Mammal* pc = new Cat("black", "10");
 pc->print();
 Mammal::printCount();
 Dog::printCount();
 Cat::printCount();
 cout << endl;
 
 delete pm;
 cout << "Deltet a mammal:" <<endl;
 Mammal::printCount();
 Dog::printCount();
 Cat::printCount();
 cout << endl;
 
 delete pd;
 cout << "Deltet a dog:" <<endl;
 Mammal::printCount();
 Dog::printCount();
 Cat::printCount();
 cout << endl;
 
 delete pc;
 cout << "Deltet a cat:" <<endl;
 Mammal::printCount();
 Dog::printCount();
 Cat::printCount();
 cout << endl;
 
 cout << "Main function ends" << endl;
 system("pause");
 return 0;
} 
