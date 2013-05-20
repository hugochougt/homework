#include <stdio.h>

int main()
{
    int t,i,n,a[2001],count,s,p;
    double m[2001],sum;
    char str[2001];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%*c",&n);//输入字符串前要加%*c 
        gets(str);
        for(i=0,count=0;i<n;i++)
        {
            a[i] = str[i] - '0';
            if(a[i]==1)
                count++;
        }
        //for(i=0;i<n;i++)
        //    printf("%d ",a[i]);
        //printf("\n");
        //system("pause");
        for(i=0,sum=0.0;i<n;i++)
        {
            scanf("%lf",m+i);
            if(a[i]==1)
                sum+=m[i];
        }
        //printf("%lf\n",sum);
        s = ((int)sum)/10;
        //printf("%d\n",s);
        //system("pause");
        switch(s)
        {
            case 0:p=0;break; 
            case 1:p=3;break;
            case 2:p=5;break;
            case 3:p=10;break;
            case 4:p=15;break;
            case 5:p=20;break;
            case 6:p=25;break;
            case 7:p=30;break;
            case 8:p=35;break;
            default:p=40;break;   
        }
        printf("Samuel was accused with %d case(s),and he will stay in the prison for %d year(s).\n",count,p);
    } 
}
