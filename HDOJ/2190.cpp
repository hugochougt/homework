#include<iostream>
using namespace std;
int main(void)
{
    double a[31]={0,1,3};
    int T,n,i;  
    for(i=3;i<=30;i++)
        a[i]=a[i-1]+2*a[i-2];
    cin>>T;
    while(T--)
    {
        cin>>n;
        cout<<a[n]<<endl;    
    }  
    return 0;
}
