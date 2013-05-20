#include<cstdio>
using namespace std;
int main()
{
    int t,n,tag=0;
    char ch;
    scanf("%d%*c",&t);
    while(t--)
    {
        if(!tag) tag=1;
        else printf("\n");
        scanf("%c %d%*c",&ch,&n);
        int v_w=1,uh,lh,tmp=n-3,tt,i,j,lens,lenl;
        v_w+=n/6;
        tt=tmp%2;
        lh=tmp/2+tt;
        uh=tmp-lh;
        lens=v_w+lh;
        lenl=v_w+lens;
        for(i=1;i<=lens;i++)
        {
            if(i<=v_w)   printf(" ");
            else        printf("%c",ch);
        }
        printf("\n");
        for(i=1;i<=uh;i++)
        {
            for(j=1;j<=lenl;j++)
            {
                if(j<=v_w||j>v_w+lh)
                    printf("%c",ch);
                else
                    printf(" ");
            }
            printf("\n");
        }
        for(i=1;i<=lens;i++)
        {
            if(i<=v_w)   printf(" ");
            else        printf("%c",ch);
        }
        printf("\n");
        for(i=1;i<=lh;i++)
        {
            for(j=1;j<=lenl;j++)
            {
                if(j<=v_w||j>v_w+lh)
                    printf("%c",ch);
                else
                    printf(" ");
            }
            printf("\n");
        }
        for(i=1;i<=lens;i++)
        {
            if(i<=v_w)   printf(" ");
            else        printf("%c",ch);
        }
        printf("\n");
    }
    return 0;
}
