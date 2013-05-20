#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int judge(char a[],int m);
	char s[81];
	int n,d,i;
	
	scanf("%d%*c",&n);
	
	while(n--){
			gets(s);
			if(s[0]!='_'&&!isalpha(s[0])){
				printf("no\n");
				continue;
			}
			for(d=i=1;s[i];i++)
				if(s[i]!='_'&&!isalnum(s[i])){
					d=0;
					break;;
				}
			if(d)
				printf("yes\n");
			else
				printf("no\n");
			}
	
	return 0;
}
