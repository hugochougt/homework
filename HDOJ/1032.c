#include <stdio.h>
int main(void)
{
	int m,n,c,i,t,N,M;
	int fun(int a);
	while(scanf("%d%d",&n,&m)!=EOF)
	{
        N=n;M=m;
        if(N>M)
        {
            t=N;N=M;M=t;    
        }
		c=0;
		for(i=N;i<=M;i++)
			if(fun(i)>c)
				c=fun(i);
		printf("%d %d %d\n",n,m,c);

	}    
	return 0;
}

int fun(int a)
{
	int count=1;
	START:
	if(1==a)	return count;
	else if(1==a%2)		
	{
		a=3*a+1;
		count++;
	}
	else	
	{
		a=a/2;
		count++;
	}
	goto START;	
}
