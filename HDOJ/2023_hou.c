#include<stdio.h>
struct student
{
    double score[5];    
    double sum_stu[50];
    double ave_stu[50];    
}stu[50];

int main(void)
{
    int i,j,m,n,c;
    double sum_score[5],ave_score[5];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                scanf("%lf",&stu[i].score[j]);
        
        for(i=0;i<m;i++)
            sum_score[i]=0;
        
        for(i=0;i<n;i++) 
        {
            for(j=0,stu[i].sum_stu[i]=0.0;j<m;j++)
            {
                stu[i].sum_stu[i]+=stu[i].score[j];
                sum_score[j]+=stu[i].score[j];
            }                   
        }   
        
        for(i=0;i<n;i++)
            stu[i].ave_stu[i]=stu[i].score[i]/m;
        for(i=0;i<m;i++)
            ave_score[i]=sum_score[i]/n;
        for(i=0;i<n;i++)
            printf("%.2lf%c",stu[i].sum_stu[i],i<n-1?' ':'\n');
        for(j=0;j<m;i++)
            printf("%.2lf%c",ave_score[j],i<n-1?' ':'\n');
    }    
    return 0;
}
