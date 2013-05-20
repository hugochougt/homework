#include<iostream>
using namespace std;
int main()
{
    int a[101002]={0},n;
    for(int i=1;i<=317;i++)
        a[i*i]=1;
    while(cin>>n)    
    {
        cout << a[n] << endl;
        /*if(1==n) cout << "1" << endl;
        else{
        a=new int[n+1];
        memset(a,1,sizeof(int)*(n+1));
        //for(i=1;i<=n;i++)
        //    cout << a[i] << " ";
        //cout << endl;
        for(i=2;i<=n;i++)
            for(j=i;j<=n;j++)
            {
                if(j%i==0)
                {
                    if(!a[j])
                        a[j]=1;
                    else
                        a[j]=0;
                }
            }
        cout << a[n] << endl;}*/
    }
}
