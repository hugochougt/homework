#include<iostream>
using namespace std;
int main()
{
    int t;
    double p,q;
    cin >> t;
    while(t--)
    {
        cin >> p >> q;
        if(p*52.0-q>=0.0)
            cout << "Oh,Samuel's hope will come true,thanks to the DcSLs." << endl;
        else
            cout << "Unfortunately,Samuel's hope will not come true,more tourists are welcomed!" << endl;
    }
    return 0;
}
