#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n,m,D;
    while(cin>>n>>m)
    {
        if((0==n)&&(0==m))
            break;
        D=n*n-4*m;
        if(D<0)
        {
            cout<<"No"<<endl;
        }
        else
        {
            double x1,x2;
            x1=(n+sqrt((double)D))*0.5;
            x2=(n-sqrt((double)D))*0.5;
            if((x1-(int)x1==0.0)&&(x2-(int)x2==0.0))
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
    return 0;
}
