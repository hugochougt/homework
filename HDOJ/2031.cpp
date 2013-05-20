#include<iostream>
#include<iomanip>
using namespace std;
void ttor(int n,int r)
{
    if(n)
    {
        ttor(n/r,r);
        cout<<setiosflags(ios::uppercase)<<hex<<n%r;
    }    
}
int main()
{
    int n,r;
    while(cin>>n>>r)
    {
        if(n<0)
        {
            n=-n;
            cout<<"-";
            ttor(n,r);
        }
        else if(!n)
        {
            cout<<"0"<<endl;
        }
        else
        {
            ttor(n,r);
        }
        cout<<endl;
    }
    return 0;
}
