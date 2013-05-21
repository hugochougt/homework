#include <iostream>
using namespace std;
class A
{
public:
	virtual void fun()
	{
		cout<<"A::fun() called.\n";
	}
};
class B:public A
{
	void fun()
	{
		cout<<"B::fun() called.\n";
	}
};
void ffun(A *pa)
{
	pa->fun();
}
int main()
{
	A *pa=new A;
	ffun(pa);
	B *pb=new B;
	ffun(pb);
	system("pause");
	return 0;
}
