#include<iostream>
using namespace std;
class A
{
public:
	A()
	{
		a1=a2=0;
		cout<<"Default constructor called.\n";
	}
	A(int i,int j);
	~A()
	{
		cout<<"Destructor called.\n";
	}
	void Print()
	{
		cout<<"a1="<<a1<<','<<"a2="<<a2<<endl;
	}
private:
	int a1,a2;
};

A::A(int i,int j)
{
	a1=i;
	a2=j;
	cout<<"Constructor called.\n";
}

int main()
{
	A a,b(5,8);
	a.Print();
	b.Print();
	system("pause");
	return 0;
}
