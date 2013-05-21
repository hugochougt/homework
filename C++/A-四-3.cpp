#include<iostream>
using namespace std;
class A
{
public:
	A(int i,int j)
	{
		a1=i;
		a2=j;
	}
	void Print()
	{
		cout<<a1<<','<<a2<<endl;
	}
private:
	int a1,a2;
};

class B
{
public:
	B() : b(0)
	{
}
	B(int i) : b(i)
	{
	}
	void Print()
	{
		cout<<b<<endl;
	}
private:
	int b;
};

class C: public A
{
public:
	C(int i,int j,int k,int l):A(i,j),c(l)
	{
	}
	void Print()
	{
		A::Print();
		b.Print();
		cout<<c<<endl;
	}
private:
	B b;
	int c;
};

int main()
{
	A a(7,8);
	a.Print();
	B b(9);
	b.Print();
	C c(4,5,6,7);
	c.Print();
	system("pause");
	return 0;
}
