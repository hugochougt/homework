//A program that uses an overload opertor in a struct

#include<iostream>
#include<string>

using namespace std;

struct CarType
{
    string maker;
    int year;
    float price;
    bool operator > (CarType car)
    {
        if(price > car.price)
            return true;
        else
            return false;
    }
};

int main(void)
{
    CarType myCar,yourCar;
    
    myCar.maker = "Mercedes";   //I wish
    myCar.year = 2010;
    myCar.price = 4488.50;
    cout << "Enter the price of your car: ";
    cin >> yourCar.price;
    
    if(myCar > yourCar)
        cout << "The price of my car is more than yours!" << endl;
    system("pause");   
    return 0;
    }
