#include<stdio.h>

int main(void)
{
    int a[5844]={0};
    int i,j,k,n,t;
    for(i=1;i<=5843;i++)
        a[i][0]=i;
    for(i=1;i<=7;i++)
        a[i][1]=i;
    for(i=8,k=8;i<=2000000000;i++)
    {
        t=i;
        if((double)t/2.0-t/2<=0.00000001)
        {
            for(j=i-1,t/=2;j>1;j--)
                if(t==a[j][1])
                {
                    a[k][1]=i;
                    k++;
                    break;    
                }    
        }
        else if((double)t/3.0-t/3<=0.00000001)
             {
                for(j=i-1,t/=3;j>1;j--)
                    if(t==a[j][1])
                    {
                        a[k][1]=i;
                        k++;
                        break;    
                    }           
             }
        else if((double)t/5.0-t/5<=0.00000001)
             {
                for(j=i-1,t/=5;j>1;j--)
                    if(t==a[j][1])
                    {
                        a[k][1]=i;
                        k++;
                        break;    
                    }           
             }    
        else if((double)t/7.0-t/7<=0.00000001)
             {
                for(j=i-1,t/=7;j>1;j--)
                    if(t==a[j][1])
                    {
                        a[k][1]=i;
                        k++;
                        break;    
                    }           
             } 
    }
    while(scanf("%d",&n),n)
        printf("The %dst humble number is %d.\n",n,a[n][1]);
    return 0;    
}
