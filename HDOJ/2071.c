#include <stdio.h>

int main(void)
{
	int t,n;
	double max,a;
	scanf("%d",&t);
	while(t--&&scanf("%d",&n)){
		max=0;
		while(n--&&scanf("%lf",&a))
			if(a>max)
				max=a;
		printf("%.2lf\n",max);
	}	
	return 0;
}