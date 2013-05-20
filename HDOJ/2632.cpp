#include<iostream>
using namespace std;
int main()
{
    int t,i;
    double op,sp,p;
    cin >> t;
    while(t--)
    {
        cin >> op >> sp >> p;
        if(op < sp)
            cout << "Samuel will change the appearance for 0 time(s),before he decide to sell it." << endl;
        else
        {
            p = 1 - p;
            for(i = -1;op >= sp;i++)
                op*=p;
            cout << "Samuel will change the appearance for " << i << " time(s),before he decide to sell it." << endl;
        }
    }
    return 0;
}
