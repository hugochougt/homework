#include<iostream>
using namespace std;
int main()
{
    int cal,fat,cbd,prt;
    double max,min;
    while(cin>>cal>>fat>>cbd>>prt)
    {
        if(!cal && !fat && !cbd && !prt)    break;
        max=min=0.0;
        if(fat>0)
        {
            max+=(fat+0.5)*9.0;
            min+=(fat-0.5)*9.0;
        }
        else
            max+=0.5*9.0;
        if(cbd>0)
        {
            max+=(cbd+0.5)*4.0;
            min+=(cbd-0.5)*4.0;
        }
        else
            max+=0.5*4.0;
        if(prt>0)
        {
            max+=(prt+0.5)*4.0;
            min+=(prt-0.5)*4.0;
        }
        else
            max+=0.5*4.0;
        if((max-cal)>0.000001&&(cal-min)>0.000001)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
