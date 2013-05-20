/* Note:Your choice is C IDE */
#include "stdio.h"
#define N 10000

void main()
{
    int a[N];
    int i,j,k,t,n;
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    	scanf("%d",&a[i]);
    	
    for(i=0;i<n-1;i++){
    	k=i;
    	for(j=i+1;j<n-1;j++)
    		if(a[j]<a[k])
    			k=j;
    		if(k!=i){
    			t=a[i];
    			a[i]=a[k];
    			a[k]=t;
    			}
    }
    
    for(i=0;i<n;i++)
    	printf("%d ",a[i]);
}

