#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--)    
    {
        cin>>n;
        cout << int((n+1)*pow(2.0,double(n-2))) << endl;
    }
    return 0;
}
