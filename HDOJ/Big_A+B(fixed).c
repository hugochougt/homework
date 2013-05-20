/* Note:Your choice is C IDE */
#include "stdio.h"
#include "string.h"
#define N 1000
int main(void)
{
	char s[N];
    int a[N],b[N],c[N];
    long alen,blen,clen;
    int i,j,n;
    
    while(scanf("%d",&n)!=EOF){
    	for(j=0;j<n;j++){
    		scanf("%s",s);
    		alen=strlen(s);
    
    		for(i=alen-1;i>=0;i--)
    			a[alen-i]=s[i]-'0';
    
   			scanf("%s",s);
   	 		blen=strlen(s);
    
    		for(i=blen-1;i>=0;i--)
    			b[blen-i]=s[i]-'0';
    	
    		clen=alen>blen?alen:blen;
    
    		for(i=1;i<=clen;i++)
    			c[i]=a[i]+b[i];
    	
    		for(i=1;i<=clen;i++)
    			if(c[i]>9)
    			{	
    				c[i+1]++;
    				c[i]-=10;
    				if(i==clen)
    				clen++;
    			}
    
    		for(i=clen;i>0;i--)
    			printf("%d",c[i]);
    		printf("\n");
    	}
    }
    return 0;    
}