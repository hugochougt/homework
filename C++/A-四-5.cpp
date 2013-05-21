#include <iostream>
using namespace std;
class C
{
	friend void print(C c);
public:
	C(int i) : x(i)
	{
	}
	C() : x(0)
	{
		cout<<"Default constructor called."<<x<<endl;
	}
	C(const C& c)
	{
		x = c.x;
		cout << "Copy constructor called." << x << endl;
	}
	~C()
	{
		cout<<"Destructor called."<<x<<endl;
	}
private:
	int x;
};

void print(C c)
{
	cout << c.x << endl;
}

int main()
{
	C p[4];
	int n=1;
	for(int i=0;i<4;i++)
		p[i]=C(n++);
	for(int i=0;i<4;i++)
		print(p[i]);
	system("pause");
	return 0;
}
