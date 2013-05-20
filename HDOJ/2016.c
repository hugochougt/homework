#include <stdio.h>

int main(void)
{
    void swap(int *A,int *B);
	int n,i;
    int a[100],min,index;
	
    while(scanf("%d",&n)!=EOF)
    {	
		if(n==0)	break;
		
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);	
	
    	min=a[0];index=0;
	
    	for(i=1;i<n;i++)
			if(min>a[i])
            {
				min=a[i];
				index=i;
			}
		if(index!=0)	
		  swap(&a[0],&a[index]);
		
		for(i=0;i<n;i++)
			printf("%d%c",a[i],(i<n-1?' ':'\n'));
	}    
	return 0;
}

void swap(int *A,int *B)
{
     int temp;
     temp=*A;
     *A=*B;
     *B=temp;
}
