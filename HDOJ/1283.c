#include "stdio.h"

int main(void)
{
	char s[201];
	int M1,M2,R1,R2,R3,i;
	
	while(scanf("%d%d%*c",&M1,&M2)!=EOF)
	{
		gets(s);
		
		for(i=0,R1=R2=R3=0;s[i]!='\0';i++)
		{
			switch(s[i])
			{
				case 'A':R1=M1;break;
				
				case 'B':R2=M2;break;
				
				case 'C':M1=R3;break;
				
				case 'D':M2=R3;break;
				
				case 'E':R3=R1+R2;break;
				
				case 'F':R3=R1-R2;break;	
			}	
		}	
		printf("%d,%d\n",M1,M2);
	}    
	return 0;
}