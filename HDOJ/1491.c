#include <stdio.h>

int main(void)
{
	int T,m,d,sum;
	
	scanf("%d",&T);
	
	while(T--)
	{
		scanf("%d%d",&m,&d);
		
		sum=0;
		
		if(m<10)
		{
			switch(m)
			{
				case 1:sum+=d;break;
				case 2:sum=31+d;break;
				case 3:sum=59+d;break;
				case 4:sum=90+d;break;
				case 5:sum=120+d;break;
				case 6:sum=151+d;break;
				case 7:sum=181+d;break;
				case 8:sum=212+d;break;
				case 9:sum=243+d;break;	
			}	
			printf("%d\n",294-sum);
		}
		else if(10==m)
				{
					if(d<21)
					{
						sum=273+d;
						
						printf("%d\n",294-sum);
					}
					else if(21==d)
						printf("It's today!!\n");
					
					else
						printf("What a pity, it has passed!\n");		
				}
		else
			printf("What a pity, it has passed!\n");	
	}	
	return 0;
}