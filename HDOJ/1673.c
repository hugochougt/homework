#include <stdio.h>

int main(void)
{
	int t,n,i,p[99],max,min;
	
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d",&n);
		
		for(i=0;i<n;i++)
			scanf("%d",p+i);
			
		max=min=p[0];
		
		for(i=1;i<n;i++)	
		{
			if(p[i]>max)
				max=p[i];
			else if(p[i]<min)
					min=p[i];	
		}
		
		printf("%d\n",2*(max-min));
	}	    
	return 0;
}