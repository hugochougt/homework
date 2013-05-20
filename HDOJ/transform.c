#include <string.h>
#include <stdio.h>
int main(void)
{
	char s[10];
	int a[10];
	int i,alen;
	gets(s);
	alen=strlen(s);
	for(i=alen-1;i>=0;i--)
		a[alen-i]=s[i]-'0';
	for(i=alen;i>0;i--)
		printf("%d",a[i]);
		printf("\n");  
	return 0;
}