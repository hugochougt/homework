#include <iostream>
using namespace std;
class Point
{
public:
	Point(int i,int j) 
	{
		X=i;
		Y=j;
	}
	Point(Point &rp);
	~Point()
	{
		cout<<"Destructor called.\n";
	}
	int Xcood()
	{
		return X;
	}
	int Ycood()
	{
		return Y;
	}
private:
	int X,Y;
};
Point::Point(Point &rp)
{
	X=rp.X;
	Y=rp.Y;
	cout<<"Copy Constructor called.\n";
}
int main()
{
	Point p1(6,9);
	Point p2(p1);
	Point p3=p2,p4(0,0);
	p4=p1;
	cout<<"p3=("<<p3.Xcood()<<','<<p3.Ycood()<<")\n";
	cout<<"p4=("<<p4.Xcood()<<','<<p4.Ycood()<<")\n";
	system("pause");
	return 0;
}
