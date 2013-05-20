#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
    __int64 a,b;
    while(cin >> hex >> a >> b)
    {
        int sum=a+b;
        if(sum<0)
        {
            cout << "-";
            sum=-sum;
        }
        cout << setiosflags(ios::uppercase) << hex << sum << endl;   
    }
    return 0;
}
