#include<iostream>
using namespace std;
int main()
{
    int MaxNum,i,n,sum,x;
    int a[1020];
    while(cin >> n)
    {
        if(0==n) break;
        MaxNum=-1;
        sum=0;
        for(i=0;i<n;i++)
        {
            cin >> x;
            if(x>MaxNum)
            {
                MaxNum=x;
                sum+=MaxNum;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
