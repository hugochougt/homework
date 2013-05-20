#include "stdio.h"
int main(void)
{
	int n,i,p,m;
	while(scanf("%d",&n)!=EOF){
		p=1;
		for(i=0;i<n;i++){
			scanf("%d",&m);
			if(1==m%2)
				p*=m;
		}
		printf("%d\n",p);
	}
	return 0;
}