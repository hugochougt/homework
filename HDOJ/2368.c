#include<stdio.h>
int main()
{
    int r,w,l,c=1;
    double rr,ww,ll;
    while(scanf("%d",&r)!=EOF)
    {
        if(0==r)
            break;
        scanf("%d%d",&l,&w);
        ww=0.5*w;
        ll=0.5*l;
        if((ww-r>0.0) || (ll-r>0.0))
            printf("Pizza %d does not fit on the table.\n",c);
        else
        {
            if(ll*ll+ww*ww>r*r)
                printf("Pizza %d does not fit on the table.\n",c);
            else
                printf("Pizza %d fits on the table.\n",c);
        }
        c++;
    }
    return 0;
}
