#include<iostream>
using namespace std;

const double PI = 3.14159;

class Circle         
{
public:
	Circle(double r);
	double Circumference();
	double Area();
	friend double fCircle_L(Circle &rr);
	friend double fCircle_S(Circle &rr);
private:
	double radius;
};

Circle::Circle(double r)
{
	radius = r;
}

//成员函数计算周长 
double Circle::Circumference()
{
    cout << "成员函数被调用" << endl;
	return 2 * PI * radius;
}

//成员函数计算面积 
double Circle::Area()
{
    cout << "成员函数被调用" << endl;
	return PI * radius *radius;
}

//友元函数求周长 
double fCircle_L(Circle &r)
{
    cout << "友元函数被调用" << endl;
	double L = 2 * PI * r.radius;
    return L;    
}

//友元函数求面积 
double fCircle_S(Circle &r)
{
    cout << "友元函数被调用" << endl;
	double S = PI * r.radius * r.radius;
    return S;
}

int main(void)
{
	double R;
	cout << "请输入半径: "; 
	while(cin >> R)
	{
		Circle C(R);
		
		cout << C.Circumference() << endl;
		cout << C.Area() << endl;
		
		cout << fCircle_L(C) << endl;
		cout << fCircle_S(C) << endl;
		
		cout << "\n\n请输入半径: "; 
	}
	return 0;
}
