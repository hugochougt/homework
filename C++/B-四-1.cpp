#include <iostream>
using namespace std;
void print(int);
void print(char);
void print(char *);
int main()
{
	int a(800);
	print(a);
	print('a');
	print("break");
	system("pause");
	return 0;
}
void print(int i)
{
	cout<<i<<endl;
}
void print(char i)
{
	cout<<i<<endl;
}
void print(char *i)
{
	cout<<i<<endl;
}
