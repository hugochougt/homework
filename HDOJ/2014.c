#include <stdio.h>
#include<stdlib.h>
int cmp(const int *a, const int *b)
{
    int v=*a-*b;
    if(!v)
        return 0;
    else
        return v;    
}
int main(void)
{
	int a[101],n,i,sum;
	while(scanf("%d",&n)!=EOF)
    {
        if(0==n)    break;
		for(i=0,sum=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
        }
        qsort(a, n, sizeof(int), cmp);
		sum-=(a[0]+a[n-1]);
		printf("%d\n",sum/(n-2));
	}	
	return 0;
}
