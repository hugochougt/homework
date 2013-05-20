#include<stdio.h>
void swap(double *a, double *b)
{
    double t=*a;
    *a=*b;
    *b=t;    
}
int main(void)
{
    double p1x,p1y,p2x,p2y,p3x,p3y,p4x,p4y;  
    while(scanf("%lf%lf%lf%lf",&p1x,&p1y,&p2x,&p2y)!=EOF) 
    {
        scanf("%lf%lf%lf%lf",&p3x,&p3y,&p4x,&p4y);
        
        if(p1x>p2x)
            swap(&p1x, &p2x);
        if(p1y>p2y)
            swap(&p1y, &p2y);
            
        if(p3x>p4x)
            swap(&p3x, &p4x);
        if(p3y>p4y)
            swap(&p3y, &p4y);
        
        if(p1x>p3x)
        {
            swap(&p1x,&p3x);
            swap(&p1y,&p3y);   
            swap(&p2x,&p4x); 
            swap(&p2y,&p4y); 
        }
        if(p2y<p3y)
            printf("0.00\n");
        else if(p2x>p4x && p2y>p4y)
            printf("%.2lf\n",(p4x-p3x)*(p4y-p3y));
        else
            printf("%.2lf\n",(p2x-p3x)*(p2y-p3y));
    } 
    return 0;
}
