#include<iostream>
using namespace std;
int main()
{
    __int64 a[22]={0,1,1};
    int i,n;
    for(i=3;i<=20;i++)
        a[i]=(i-1)*a[i-1];
    while(cin >> n)
    {
        cout << a[n] << endl;
    }
    return 0;
}
