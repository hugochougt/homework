#include<iostream>
using namespace std;

void fun(int *&pp)
{
    int *q;
    q = new int(3);
    cout << *q << endl;
    pp = q;
}

int main()
{
    int *p;
    fun(p);
    cout << *p << endl;
    system("pause");
    return 0;
}
