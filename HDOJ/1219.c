#include <stdio.h>

int main(void)
{
	char str[100000],i;
	int count[26],j,k;
	
	while(gets(str))
	{
		for(j=0;j<26;j++)
			count[j]=0;
			
		for(i='a',j=0;i<='z';i++,j++)
			for(k=0;str[k]!='\0';k++)
				if(i==str[k])
					count[j]++;
					
		for(j=0,i='a';j<26;j++,i++)
			printf("%c:%d\n",i,count[j]);
	
		printf("\n");
	}
	return 0;    
}