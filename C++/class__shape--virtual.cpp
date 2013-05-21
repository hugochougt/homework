#include<iostream>
#include<cmath>
using namespace std;
const double PI = 3.14159;
class Shape
{
public:
    Shape(){}
    virtual double area() = 0;
    ~Shape(){}
};
class Circle:public Shape
{
public:
    Circle(double r)
    {
        radius = r;    
    }
    double area()
    {
        return PI*radius*radius;
    }
private:
    double radius;    
};
class Retangle:public Shape
{
public:
    Retangle(double l,double w)
    {
        length = l;
        width = w;            
    }
    double area()
    {
        return width*length;    
    }
private:
    double width,length;
};
class Triangle:public Shape
{
public:
    Triangle(double a,double b,double c)
    {
        A = a;
        B = b;
        C = c;
    }
    double area()
    {
        double p=(A+B+C)/2;
        return sqrt(p*(p-A)*(p-B)*(p-C));
    }
private:
    double A,B,C;
};
int main()
{
    Shape *p[3];
    Circle circle(12.6);
    Retangle retangle(4.5,8.4);
    Triangle triangle(4,4,5.65);
    p[0]=&circle;
    p[1]=&retangle;
    p[2]=&triangle;
    double s=0;
    for(int i=0;i<3;i++)
        s+=p[i]->area();
    cout << "total of all areas=" << s << endl;
    delete []*p;
    system("pause");
    return 0;    
}
