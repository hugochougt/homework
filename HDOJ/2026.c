#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[101];
	int i,blank;
	while(gets(s))
	{
		blank = 1;
		for(i=0;s[i]!='\0';i++){
			if(s[i]==' ')	blank = 1;
			else if(blank==1){
					blank=0;
					s[i]-=32;
				}
		}	
		puts(s);
	}
	return 0;
}