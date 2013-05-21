//ตÝน้ :ว๓N! 
#include<iostream>
using namespace std;
long fac(int n)
{
    long f;
    if(0==n)
        f=1;
    else
        f=fac(n-1)*n;
    return(f);    
}

int main(void)
{
    int n;
    long y;
    cin>>n;
    y=fac(n);
    cout<<y<<endl;
    system("pause");
    return 0;     
}
