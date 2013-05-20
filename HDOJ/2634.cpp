#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t,n;
    double sum,x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        sum=0.0;
        for(int i=0;i<n;i++)
        {
            cin >> x;
            sum+=x;    
        }
        printf("The average M = %.10lf.\n",sum/n);
    }
    return 0;
}
