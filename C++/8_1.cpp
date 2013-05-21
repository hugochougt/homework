//8_1.cpp
#include<iostream>
using namespace std;

class complex   //复数类定义 
{
public:     //外部接口 
    complex(double r = 0.0, double i = 0.0)     //构造函数 
    {real = r; imag = i;}                       
    complex operator + (complex c2);            //运算符 + 重载成员函数 
    complex operator - (complex c2);            //运算符 - 重载成员函数 
    void display();                             //输出复数 
private:
    double real;        //实部 
    double imag;        //虚部 
};

complex complex::operator + (complex c2) 
{
    return complex(real + c2.real, imag + c2.imag);    
}

complex complex::operator - (complex c2)
{
    return complex(real - c2.real, imag - c2.imag);    
}

void complex::display()
{
    cout << real << " + i" << imag <<endl;
}

int main(void)
{
    complex c1(40,50),c2(10,23),c3;
    cout << "c1 = "; c1.display();
    cout << "c2 = "; c2.display();
    c3 = c1 - c2;
    cout << "c3 = c1 - c2 = ";
    c3.display();
    c3 = c1 + c2;
    cout << "c3 = c1 + c2 = ";
    c3.display();
    system("pause");
    return 0;
}
