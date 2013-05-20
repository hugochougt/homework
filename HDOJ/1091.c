/* Note:Your choice is C IDE */
#include "stdio.h"
void main()
{
	int a,b;
	while((scanf("%d %d",&a,&b))!=EOF){
		if((a==0)&&(b==0))
			break;
		printf("%d\n",a+b);
	}		
}