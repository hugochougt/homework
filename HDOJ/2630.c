#include<stdio.h>
#include<string.h>
int main()
{
    int math(char *);
    char name[50];
    int H,M,S,m,s,mm,ss,t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%*c",&n);
        m=0;
        s=0;
        while(n--)
        {
            scanf("%s%d:%d",name,&mm,&ss);
            if(math(name)==1)
            {
                m+=mm;
                s+=ss;
            }    
        }
        S=s%60;
        m+=s/60;
        M=m%60;
        H=m/60;
        printf("Samuel will watch Channel[V] for %d hour(s),%d minute(s),%d second(s).\n",H,M,S);
    }
    return 0;
}
int math(char *s)
{
    if(!strcmp(s,"S.H.E"))
        return 1;
    else if(!strcmp(s,"Jay"))
        return 1;
    else if(!strcmp(s,"Elva"))
        return 1;
    else if(!strcmp(s,"Jolin"))
        return 1;
    else if(!strcmp(s,"Aska"))
        return 1;
    else if(!strcmp(s,"Yoga"))
        return 1;
    else
        return 0;
}
