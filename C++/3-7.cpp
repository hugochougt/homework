//3-7.cpp
#include<iostream>
using namespace std;

short fun(unsigned short int a,unsigned short int b)
{
    if(0==b)
        return -1;
    else
        return a/b;    
}

int main(void)
{
    unsigned short int x,y;
    cin>>x>>y;
    cout<<fun(x,y)<<endl;
    system("pause");
    return 0;
}
