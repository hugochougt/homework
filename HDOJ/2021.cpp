#include<iostream>
using namespace std;
int main(void)
{
    int T,a[100],i,c;
    while(cin >> T,T)
    {
        for(i=0;i<T;i++)
            scanf("%d",a+i);
        for(i=0,c=0;i<T;i++)
        {
        if(a[i]>=100)
        {
            c+=a[i]/100;
            a[i]%=100;    
        }
        if(a[i]>=50)
        {
            
            c+=a[i]/50;
            a[i]%=50;
        }
        if(a[i]>=10)
        {
            c+=a[i]/10;
            a[i]%=10;    
        }
        if(a[i]>=5)
        {
            c+=a[i]/5;
            a[i]%=5;    
        }
        if(a[i]>=2)
        {
            c+=a[i]/2;
            a[i]%=2;    
        }
        c+=a[i];
    }
        cout << c << endl;
    } 
    return 0;   
}
