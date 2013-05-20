#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int n,i,j,c[100],max,sum,max_i,t_n;
    char str[1001][16],t[16];
    while(scanf("%d%*c",&n)!=EOF)
    {
        if(0==n) break;
        for(i=0;i<n;i++)
            gets(str[i]);
        t_n=n-1;
        for(i = 0; i < t_n; i++)
            {
                for(j = 0; j <t_n-i; j++)
                {
                    if(strcmp(str[i], str[j]) > 0)
                    {
                        strcpy(t, str[i]);
                        strcpy(str[i], str[j]);
                        strcpy(str[j], t);
                    }    
                }    
            }
            
        //for(i=0;i<=n;i++)
        //    puts(str[i]);
        memset(c,0,n*4);
        //for(i=0;i<n;i++)
        //{
        //    printf("%d ",c[i]);
        //}
        j=0;c[0]=1;
        for(i=1;i<=n;i++)
        {
            if(!strcmp(str[i],str[i-1]))
                c[j]++;
            else
            {
                j++;
                c[j]++;
            }
        }
        j--;
        //for(i=0;i<=j;i++)
        //{
        //    printf("%d ",c[i]);
        //}
        //printf("\n");
        max=c[0];max_i=0;sum=0;
        for(i=1;i<j;i++)
        {
            if(max<c[i])
            {
                max=c[i];
                max_i=i;
            }
        }
        //printf("%d %d\n",max,max_i);
        //for(i=0;i<max_i;i++)
        //{
        //    sum+=c[i];
        //}
        //printf("%d\n",sum);
        printf("%s\n",str[sum]);
    }
    return 0;
}
