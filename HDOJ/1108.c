/* Note:Your choice is C IDE */
#include "stdio.h"

int main(void)
{
	int m,n,temp,a,b;
	while(scanf("%d %d",&m,&n)!=EOF){
		if(m<n){
			temp=m;
			m=n;
			n=temp;
		}
		a=m;
		b=n;
		while(b){
			temp=a%b;
			a=b;
			b=temp;
		}
		printf("%d\n",m*n/a);
	}
	return 0;	
}