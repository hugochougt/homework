#include<iostream>
#include<string>

using namespace std;

class Mammal
{
    public:
        Mammal(char *c, double w)
        {
            color = new char[sizeof(c)+1];
            strcpy(color, c);
            weight = w;
            count++;
        }
        virtual ~Mammal()
        {
            count--;
            delete []color;
        }
        virtual void print()
        {
            cout << "\nMammal" << endl;
            cout << "Color: " << color << endl;
            cout << "Weight: " << weight << endl;    
        }
        static void show_amount()
        {
            cout << "Amount of mammals: " << count << endl;    
        }
    private:  
        char *color;
        double weight;
        static int count;
};
int Mammal::count = 0;

class Dog : public Mammal
{
    public:
        Dog(char *c, double w) : Mammal(c, w)
        {
            color = new char[sizeof(c)+1];
            strcpy(color, c);
            weight = w;
            count++;
        }
        void print()
        {
            cout << "\nDog" << endl;
            cout << "Color: " << color << endl;
            cout << "Weight: " << weight << endl;   
        }
        static void show_amount()
        {
            cout << "Amount of dogs: " << count << endl;    
        }
        virtual ~Dog()
        {
            count--;
        }
    private:
        char *color;
        double weight;
        static int count;    
};
int Dog::count = 0;

class Cat : public Mammal
{
    public:
        Cat(char *c, double w) : Mammal(c, w)
        {
            color = new char[sizeof(c)+1];
            strcpy(color, c);
            weight = w;
            count++;    
        }
        void print()
        {
            cout << "\nCat" << endl;
            cout << "Color: " << color << endl;
            cout << "Weight: " << weight << endl;
        }
        static void show_amount()
        {
            cout << "Amount of cats: " << count << endl;    
        }
        virtual ~Cat()
        {
            count--;  
        }
    private:
        char *color;
        double weight;
        static int count;
};
int Cat::count = 0;

int main()
{
    Mammal::show_amount();
    Dog::show_amount();
    Cat::show_amount();
    
    cout << "\nCreat a mammal." << endl;
    Mammal m1("black", 2.4);
    m1.print();
    
    cout << endl;
    Mammal::show_amount();
    Dog::show_amount();
    Cat::show_amount();
    cout << endl;
    
    cout << "\nCreat a mammal." << endl;
    Mammal m2("yellow", 3.3);
    m2.print();
    
    cout << "\nCreat a dog." << endl;
    Dog d1("white", 4.4);
    d1.print();
    
    cout << "\nCreat a cat." << endl;
    Cat c1("green", 2.2);
    c1.print();
    
    cout << endl;
    Mammal::show_amount();
    Dog::show_amount();
    Cat::show_amount();
    cout << endl;
    
    cout << "\nCreat a mammal." << endl;
    Mammal *m3 = new Mammal("brown", 21);
    m3->print();
    
    cout << endl;
    Mammal::show_amount();
    Dog::show_amount();
    Cat::show_amount();
    cout << endl;
    
    cout << "\nCreat a dog." << endl;
    Mammal *m4 = new Dog("yellow", 12);
    m4->print();
    
    cout << endl;
    Mammal::show_amount();
    Dog::show_amount();
    Cat::show_amount();
    cout << endl;
    
    cout << "\nCreat a cat." << endl;
    Mammal *m5 = new Cat("while", 3);
    m5->print();
    
    cout << endl;
    Mammal::show_amount();
    Dog::show_amount();
    Cat::show_amount();
    cout << endl;
    
    delete m5;
    cout << "Delete a cat..." << endl;
    cout << endl;
    Mammal::show_amount();
    Dog::show_amount();
    Cat::show_amount();
    cout << endl;
    
    delete m4;
    cout << "Delete a dog.." << endl;
    cout << endl;
    Mammal::show_amount();
    Dog::show_amount();
    Cat::show_amount();
    cout << endl;
    
    delete m3;
    cout << "Delete a mammals.." << endl;
    cout << endl;
    Mammal::show_amount();
    Dog::show_amount();
    Cat::show_amount();
    cout << endl;
    
    cout << "Main function ends.\n" << endl;
    
    system("pause");
    return 0;
}
