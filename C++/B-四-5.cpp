#include <iostream>
using namespace std;
class C
{
public:
	C(int i)
	{
		c=i;
	}
	C()
	{
		c=0;
		cout<<"Default constructor called."<<c<<endl;
}
	~C()
	{
		cout<<"Destructor called."<<c<<endl;
	}
	void Print()
	{
		cout<<c<<endl;
	}
private:
	int c;
};

int main()
{
	C *p;
	p=new C[4];
	int n=1;
	for(int i=0;i<4;i++)
		p[i]=C(n++);
	for(int i=0;i<4;i++)
		p[i].Print();
	delete []p;
	system("pause");
	return 0;
}
