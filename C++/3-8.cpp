//3-8.cpp
#include<iostream>
using namespace std;
void st(double F)
{
    cout<<(F-32)*5/9<<endl;    
}

int main(void)
{
    double F;
    cin>>F;
    st(F);
    system("pause");
    return 0;    
}
