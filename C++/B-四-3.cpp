#include <iostream>
using namespace std;
class B
{
public:
	B(int i,int j)
	{
		b1=i;
		b2=j;
	}
	void Print()
	{
		cout<<b1<<','<<b2<<endl;
	}
private:
	int b1,b2;
};
class C
{
public:
	C(int i)
	{
		c=i;
	}
	void Print()
	{
		cout<<c<<endl;
	}
private:
	int c;
};
class A
{
public:
	A(int i,int j,int k, int l):c(i),b(j,k)
	{
		a=l;
	}
	void Print()
	{
		b.Print();
		c.Print();
		cout<<a<<endl;
	}
private:
	B b;
	C c;
	int a;
};

int main()
{
	B b(7,8);
	b.Print();
	C c(9);
	c.Print();
	A a(4,5,6,7);
	a.Print();
	system("pause");
	return 0;
}
