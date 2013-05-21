#include<iostream>
#include<cmath>
using namespace std;

const double Pi = 3.14159;

class Circle
{
public:
	Circle(double r)
	{
		radius = r;
	}
	double Radius()
	{
		return radius;
	}
	~Circle(){}
private:
	double radius;
};

class Ball : public Circle
{
public:
	Ball(double r) : Circle(r){}
	double volume()
	{
		return 4*Pi*pow(Radius(), 3)/3;
	}
	double surface_area()
	{
		return 4*Pi*pow(Radius(), 2);
	}
	~Ball(){}
private:
	double radius;
};

class Column : public Ball
{
public:
	Column(double r, double h) : Ball(r)
	{
		high = h;
	}
	double volume()
	{
		return high*Pi*pow(Radius(), 2);
	}
	double surface_area()
	{
		return 2*Pi*pow(Radius(), 2)+2*Pi*Radius()*high;
	}
	~Column(){}
private:
	double high;
};

class Cone : public Ball
{
public:
	Cone(double r, double h) : Ball(r)
	{
		high = h;
	}
	double volume()
	{
		return high*Pi*pow(Radius(), 2)/3;
	}
	double surface_area()
	{
		return Pi*pow(Radius(), 2)+Pi*Radius()*sqrt(pow(Radius(), 2)+pow(high, 2));
	}
	~Cone(){}
private:
	double high;
};

int main()
{
	double R,H;
	cout << "\nInput the radius: ";
	cin >> R;
	Ball B(R);
	cout << "The volume of a ball( R = " << R << " ) is " << B.volume() << endl;
	cout << "The surface area of a ball( R = " << R << " ) is " << B.surface_area() << endl;
	cout << "\nInput the radius: ";
	cin >> R;
	cout << "Input the heigh: ";
	cin >> H;
	Column C(R, H);
	cout << "The volume of a column( R = " << R << ", H = " << H << " ) is " << C.volume() << endl;
	cout << "The surface area of a column( R = " << R << ", H = " << H << " ) is " << C.surface_area() << endl;
	cout << "\nInput the radius: ";
	cin >> R;
	cout << "Input the heigh: ";
	cin >> H;
	Cone Cc(R, H);
	cout << "The volume of a cone( R = " << R << ", H = " << H << " ) is " << Cc.volume() << endl;
	cout << "The surface area of a cone( R = " << R << ", H = " << H << " ) is " << Cc.surface_area() << endl;
	return 0;
}