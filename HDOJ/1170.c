#include <stdio.h>
int main(void)
{
	int T,n,m,D;
	double F;
	char c;    
	
	scanf("%d%*c",&T);
	
	while(T--)
	{
		scanf("%c %d %d%*c",&c,&n,&m);
		
		switch(c)
		{
			case '+':printf("%d\n",n+m);break;
			case '-':printf("%d\n",n-m);break;
			case '*':printf("%d\n",n*m);break;
			case '/':F=(double)n/m;
                     if(0==F-(int)F)
                        printf("%d\n",(int)F);
                     else
                        printf("%.2lf\n",F);
                        break;
            default:break;
		}	
	}
	return 0;
}
