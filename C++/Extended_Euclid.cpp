#include<iostream>
using namespace std;
int x, y, q;
void Extended_Euclid(int a, int b)
{
    if(0 == b)    
    {
        x = 1;
        y = 0;    
        q = a;
    }
    else
    {
        Extended_Euclid(b, a % b);
        int tmp = x;
        x = y;
        y = tmp - a / b * y;
    }
}
int main()
{
    int a,b;
    while(cin >> a >> b)    
    {
        Extended_Euclid(a,b);
        cout << "X: " << x << "\tY: " << y << "\tQ: " << q << endl;
    }
}
