#include<stdio.h>
#include<string.h>
int main(void)
{
    char s1[50],s2[50],s_t[104];
    int n,i,len_s1,len_s2,len_half,len,j,k;
     
    scanf("%d%*c",&n);
    
    while(n--)   
    {
        gets(s1);
        gets(s2);
        
        len_s1=strlen(s1);
        len_s2=strlen(s2);
        
        len_half=len_s1/2;
        len=len_s1+len_s2;
        
        for(i=0;i<len_half;i++)
            s_t[i]=s1[i];
        for(j=0,i=len_half;j<len_s2;i++,j++)
            s_t[i]=s2[j];
        for(j=len_half,i=len_half+len_s2;i<len;i++,j++)
            s_t[i]=s1[j];
        for(i=0;i<len;i++)
            printf("%c",s_t[i]);
            printf("\n");
    }
    return 0;
}
