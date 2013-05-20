#include <stdio.h>
#include <string.h>
int main(void)
{
	char s[101];
	int j,n,a,e,i,o,u;
	scanf("%d%*c",&n);
	while(n--){
		gets(s);
		a=e=i=o=u=0;
		for(j=0;s[j];j++){
			if(s[j]=='a')	a++;
			else if(s[j]=='e')	e++;
			else if(s[j]=='i')	i++;
			else if(s[j]=='o')	o++;
			else if(s[j]=='u')	u++;
		}
		printf("a:%d\n",a);
		printf("e:%d\n",e);
		printf("i:%d\n",i);		
		printf("o:%d\n",o);
		printf("u:%d",u);
	}    
	return 0;
}