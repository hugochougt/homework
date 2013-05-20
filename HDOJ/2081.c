#include "stdio.h"
int main(void)
{
	int N,a[6]={6},i,j,k;
	char s[11];
	while(scanf("%d",&N)!=EOF){
		for(i=0;i<N;i++){
			scanf("%s",s);
			for(k=1,j=6;j<11;j++,k++)
				a[k]=s[j]-'0';
			for(k=0;k<6;k++)
				printf("%d",a[k]);
				printf("\n");
		}
	}
	return 0;
}