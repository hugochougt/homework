#include <stdio.h>

int main(void)
{
    int n,CHN[100],JPN[100],i,c,j;
    void sort(int *p,int n);
    while(scanf("%d",&n)!=EOF)
    {
         if(0==n)  break;
                              
         for(i=0;i<n;i++)
            scanf("%d",CHN+i);
         
         for(i=0;i<n;i++)
            scanf("%d",JPN+i);
         
         sort(&CHN[0],n);
         sort(&JPN[0],n); 
         
         c=j=0;
         
         for(i=0;i<n;i++)
         {
             if(CHN[i]>JPN[i])
                c+=2;
             else if(CHN[i]<JPN[i])
                     j+=2;
             else
                    {c++;j++;}
         }                   
         printf("%d vs %d\n",c,j);  
    }    
    return 0;
}

void sort(int *p,int n)
{
    int i,j,t;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-1-i;j++)
            if(*(p+j)<*(p+j+1))
            {
                t=*(p+j);
               *(p+j)=*(p+j+1);
               *(p+j+1)=t;   
            }    
}
