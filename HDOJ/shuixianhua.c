#include "stdio.h"

int main(void)
{
	int i,j,k,s1,s2;
	for(i=1;i<10;i++)
		for(j=0;j<10;j++)
			for(k=0;k<10;k++)
			{
				s1=i*i*i+j*j*j+k*k*k;
				s2=i*100+j*10+k;
				if(s2==s1)
					printf("%d\n",s1);
			}
	return 0;		
}