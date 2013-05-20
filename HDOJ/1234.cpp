//解法一:时间用字符串 
//解法二:时间转换成秒 
#include<cstdio>
using namespace std;
struct p
{
    char name[25];
    int sh,sm,ss;
    int eh,em,es;
};

void swap(struct p *a, struct p *b)
{
    struct p tmp=(*a);
    (*a)=(*b);
    (*b)=tmp;
}

int main()
{
    int t,i,n;
    struct p *pp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%*c",&n);
        pp=new struct p[n+1];
        for(i=0;i<n;i++)
            scanf("%s %d:%d:%d %d:%d:%d",pp[i].name,&pp[i].sh,&pp[i].sm,&pp[i].ss,&pp[i].eh,&pp[i].em,&pp[i].es);
        if(1==n)
            printf("%s %s\n",pp[0].name,pp[0].name);
        else
        {
            struct p min=pp[0],max=pp[0];
            for(i=1;i<n;i++)
            {
                if(pp[i].sh<min.sh)
                    swap(&pp[i],&min);
                else if(pp[i].sh==min.sh)
                    {
                        if(pp[i].sm<min.sm)
                            swap(&pp[i],&min);
                        else if(pp[i].sm==min.sm)
                            {
                                if(pp[i].ss<min.ss)
                                    swap(&pp[i],&min);
                            }
                    }
                if(pp[i].eh>max.eh)
                    swap(&pp[i],&max);
                else if(pp[i].eh==max.eh)
                    {
                        if(pp[i].em>max.em)
                            swap(&pp[i],&max);
                        else if(pp[i].em==max.em)
                            {
                                if(pp[i].es>max.es)
                                    swap(&pp[i],&max);
                            }
                    }
            }
            printf("%s %s\n",min.name,max.name);
        }
    }
    return 0;
}
