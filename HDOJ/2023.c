#include<stdio.h>

struct ss
{
    double score[6];
    double sum;
    double ave;
}std[51];

int main(void)
{
    int n,m,i,j,c,tag;
    double SUM[51],AVE[6];
    
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<n;i++)
            for(j=0,std[i].sum=0.0;j<m;j++)
            {
                scanf("%lf",&std[i].score[j]);
                std[i].sum+=std[i].score[j];
            }
            
        for(i=0;i<n;i++)
        {
            std[i].ave=std[i].sum/m;  
        }
        
        for(i=0;i<m;i++)
            for(j=0,SUM[i]=0.0;j<n;j++)
                SUM[i]+=std[j].score[i];
                
        for(i=0;i<m;i++)
            AVE[i]=SUM[i]/n;
            
        for(i=0,c=0;i<n;i++)
        {
            tag=1;
            for(j=0;j<m;j++)
            {
                if(std[i].score[j]<AVE[j])
                {
                    tag=0;
                    break;
                } 
            }
            if(tag==1) c++;
        }
        
        printf("%.2lf",std[0].ave);
        for(i=1;i<n;i++)
            printf(" %.2lf",std[i].ave);
        printf("\n");
        
        printf("%.2lf",AVE[0]);
        for(i=1;i<m;i++)
            printf(" %.2lf",AVE[i]);
        printf("\n");
        
        printf("%d\n\n",c);
    }
	return 0;
}
