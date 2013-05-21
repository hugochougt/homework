#include<iostream>
using namespace std;
class B
{
public:
	virtual void fun1()
	{
		cout<<"B::fun1().\n";
	}
	virtual void fun2()
	{
		cout<<"B::fun2().\n";
	}
	void fun3()
	{
		cout<<"B::fun3().\n";
	}
	void fun4()
	{
		cout<<"B::fun4().\n";
	}
};
class D:public B
{
public:
	void fun1()
	{
		cout<<"D::fun1().\n";
	}
	void fun2()
	{
		cout<<"D::fun2().\n";
	}
	void fun3()
	{
		cout<<"D::fun3().\n";
	}
	void fun4()
{
		cout<<"D::fun4().\n";
	}
};
int main()
{
	B *pb;
	D d;
	pb=&d;
	pb->fun1();
	pb->fun2();
	pb->fun3();
	pb->fun4();
	system("pause");
	return 0;
}
