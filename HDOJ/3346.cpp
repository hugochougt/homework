#include<iostream>
using namespace std;
int sq[11]={0,1,4,9,16,25,36,49,64,81};
int s_o_d(int n)
{
    int sum=0;
    while(n>0)    
    {
        sum+=n%10;
        n/=10;    
    }
    if(sum%8==0)
        return 1;
    else
        return 0;
}
int s_o_d_s(int n)
{
    int sum=0,tmp;
    while(n>0)
    {
        tmp=n%10;
        sum+=sq[tmp];
        n/=10;
    }
    if(sum%8==0)
        return 1;
    else
        return 0;
}
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n%8==0)
        {
            cout<<"Lucky number!"<<endl;
        }
        else if(s_o_d(n))
        {    
            cout<<"Lucky number!"<<endl;
        }
        else if(s_o_d_s(n))
        {
            cout<<"Lucky number!"<<endl;
        }
        else
            cout<<"What a pity!"<<endl;
    }
    return 0;
}
