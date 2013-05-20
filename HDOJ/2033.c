#include <stdio.h>

int main(void)
{
	int n,i,j,a[3],b[3];
	while(scanf("%d",&n)!=EOF)
		for(i=0;i<n;i++){
			for(j=0;j<3;j++)
				scanf("%d",&a[j]);
			for(j=0;j<3;j++)
				scanf("%d",&b[j]);
			for(j=0;j<3;j++)
				a[j]+=b[j];
			if(a[2]>=60){
				a[2]-=60;
				a[1]++;
			}
			if(a[1]>=60){
				a[1]-=60;
				a[0]++;
			}
			printf("%d %d %d\n",a[0],a[1],a[2]);
		}	
		return 0;
}