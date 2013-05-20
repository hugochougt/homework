#include <stdio.h>

int main(void)
{
	int fac(int a);
	void fun(char c,int n,int m);
	int T,m,n;
	char c;
	
	scanf("%d%*c",&T);
	
	while(T--)
	{	
		scanf("%c %d %d%*c",&c,&n,&m);
		
		fun(c,n,m);
	}    
	return 0;
}

int fac(int a)
{
	int i,s=1;
	for(i=1;i<=a;i++)	
		s*=i;
	return s;
}

void fun(char c,int n,int m)
{
	int res=0;
	
	if(c=='A')
		res=fac(n)/fac(n-m);
			
	else if(c=='C')
		res=fac(n)/fac(n-m)/fac(m);
			
	printf("%d\n",res);	
}