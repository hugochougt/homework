#include<stdio.h>
#include<string.h>
int main(void)
{
    char str1[1001],str2[1001];
    int i,c,len2,len1,len,j,tag;
    while(scanf("%s",str1)!=EOF)
    {
        if(!strcmp("#",str1))
            break;
        scanf("%s",str2);
        len2=strlen(str2);
        len1=strlen(str1);
       // if(len1<len2)
        //{len=len1;len1=len2;len2=len;}
        len=len1-len2;
        for(i=0,c=0;i<=len;i+=len2)
        {
            if(str1[i]==str2[0])
            {
                for(j=1,tag=1;j<len2;j++)
                    if(str1[i+j]!=str2[j])
                    {
                        tag=0;   
                        break;
                    }
                if(tag)
                    c++;
            }   
        }
        printf("%d\n",c);    
    }
    return 0;
}
