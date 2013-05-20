#include <ctype.h>
#include <stdio.h>

int main(void)
{
	char s[109];
	int i,count,tag,a[100],k,sum;
	
	while(scanf("%s",s)!=EOF)
	{
		tag=count=0;
		
		for(i=0,k=0; s[i] != '\0'; i++)		
			if(s[i] == '.')
			{
				count++;
				a[k++]=i;
            }
			else if(!isdigit(s[i]))
			     {
                    tag=1;
                    break;    
                    }
        
		if(count==3&&tag==0)
		{
            for(i=0,sum=0;i<a[0];i++)
                sum+=s[i]-'0';
            if(sum>255)
            {
                printf("NO\n"); 
                return 0;   
            }
            for(i=a[i]+1,sum=0;i<a[1];i++)
                sum+=s[i]-'0';
            if(sum>255)
            {
                printf("NO\n"); 
                return 0;   
            }
            for(i=a[i]+1,sum=0;s[i]!='\0';i++)
                sum+=s[i]-'0';
            if(sum>255)
            {
                printf("NO\n"); 
                return 0;   
            }
            for(i=a[i]+1,sum=0;i<a[2];i++)
                sum+=s[i]-'0';
            if(sum>255)
            {
                printf("NO\n"); 
                return 0;   
            }
	           printf("YES\n");
          }
		else
		  printf("NO\n");
	}    
	return 0;
}
