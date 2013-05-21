// Author by lwg
#include <iostream>
using namespace std;
const int lmax=10000;    
int c1[lmax+1],c2[lmax+1];
int main(void)
{
   	int n,i,j,k;	
    while (cin>>n)
    {
        for(i=0;i<=n;i++)
		{
            c1[i]=0;
            c2[i]=0;	
        }
		for(i=0;i<=n;i++) 
            c1[i]=1;
            
		for(i=2;i<=n;i++)		
        {
           	for(j=0;j<=n;j++)
                for(k=0;k+j<=n;k+=i)
                {  
                    c2[j+k]+=c1[j];  }
                    for(j=0;j<=n;j++)
                    {  
                        c1[j]=c2[j];
                        c2[j]=0;
                    }
                }
            cout<<c1[n]<<endl;
        }
    return 0;
}
