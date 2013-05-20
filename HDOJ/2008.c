#include "stdio.h"
int main(void)
{
	int n,i,ZH,FU,LI;
	double m;
	while(scanf("%d",&n)!=EOF){
		if(0==n)	break;
		ZH=FU=LI=0;
		for(i=0;i<n;i++){
			scanf("%lf",&m);
			if(m>0.0)	ZH++;
			else if(m<0.0)	FU++;
			else LI++;
		}
		printf("%d %d %d\n",FU,LI,ZH);
	}
	return 0;
}