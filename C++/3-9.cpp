//3-9.cpp
#include<iostream>
#include<cmath>
using namespace std;

bool isprime(int n)
{
    int i,prime=1;
    for(i=2;i<=sqrt(n);i++)    
        if(0==n%i)
            return false;   
        return true;
}

int main(void)
{
    int a;
    while(cin>>a)
    {
        if(isprime(a))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }    
    return 0;
}
