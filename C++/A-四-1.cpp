#include<iostream>
using namespace std;
int add(int , int = 5);
int main()
{
    int a(8);
    cout << "sum1 = " << add(a) << endl;
    cout << "sum2 = " << add(a,add(a)) << endl;
    cout << "sum3 = " << add(a,add(a,add(a))) << endl;
    system("pause");
    return 0;
}
int add(int i, int j)
{
    return i+j;    
}
