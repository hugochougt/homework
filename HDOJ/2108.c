#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int *px,*py,i,tag,n;
    while(scanf("%d",&n)!=EOF)
    {
        if(0==n)    break;
        px=(int *)calloc((n+1), sizeof(int));
        py=(int *)calloc((n+1), sizeof(int));
        for(i=0; i<n; i++)
            scanf("%d%d",px+i,py+i);
        px[i]=px[0];py[i]=py[0];
        for(i=1,tag=1;i<n;i++)
            if( (px[i]-px[i-1])*(py[i+1]-py[i])-(px[i+1]-px[i])*(py[i]-py[i-1]) < 0 )
            {
                tag=0;
                break;    
            }
        if(tag) printf("convex\n");
        else    printf("concave\n");
        free(px);
        free(py);
    }    
    return 0;
}
