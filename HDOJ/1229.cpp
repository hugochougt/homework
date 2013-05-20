#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int a,b,k;
     int mod[9]={1,10,100,1000,10000,100000,1000000,10000000,100000000};
    while(scanf("%d%d%d",&a,&b,&k)!=EOF)
    {
        if(!a&&!b) break;
        
        //int mod=(int)pow(10.0,(double)k);
        /*当k=2时, mod等于99!!!*/
         
        //printf("mod:%d\n",mod);
        //printf("%d\t%d\n",a%mod,b%mod);
        if(a%mod[k]==b%mod[k])
            printf("-1\n");
        else
            printf("%d\n",a+b);
    }
    return 0;
}
