#include<iostream>
using namespace std;
int main(void)
{
    int i,j,n;
    cin>>n;
    for(i=1;i<=n/2;i++)
    {
        for(j=n;j>=2*i-1;j--)
            cout<<" ";
        for(j=1;j<=2*i-1;j++)
            cout<<"*";
            cout<<endl;    
    }
    for(i=0;i<n;i++)
        cout<<"*";
        cout<<endl;
    for(i=1;i<=n/2;i++)
    {
        for(j=n;j>=2*i;j--)
            cout<<"*";
        for(j=1;j<=2*i;j++)
            cout<<" ";
            cout<<endl;   
    }   
    system("pause");
    return 0;
} 
