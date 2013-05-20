#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int A,arr[50],i,c,k;
    while(scanf("%d",&A)!=EOF)
    {
        if(0==A) break;
        c=0;
        while(A%2==0)
        {
            c++;
            A/=2;    
        }
        //printf("%d\n",c);
        printf("%.0lf\n",pow(2.0,(double)c));
    }
    return 0;
}
