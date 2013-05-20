#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{
    int s,d,x,y,t,v;
    cin >> t;
    while(t--)
    {
        cin >> s >> d;
        if(s < d)
       
            cout << "impossible" << endl;    
        else{
             v = s + d;
             if(v % 2 == 0)
                cout << v/2 << ' ' << (s-d)/2 << endl;
             else  
                cout << "impossible" << endl; 
            }
    }
    return 0;
}
