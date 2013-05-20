#include<iostream>
using namespace std;

void ttor(int n,int r)
{
    if(n)
    {
        ttor(n/r,r);
        cout<<n%r;
    }
}

int main()
{
    unsigned int m,a,b;
    __int64 sum;
    while(cin>>m)
    {
        if(0==m) break;
        cin>>a>>b;
        sum=a+b;
        if(sum==0)
            cout << 0;
        else
            ttor(sum,m);
        cout<<endl;
    }
    return 0;
}
