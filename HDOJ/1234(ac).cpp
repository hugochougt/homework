#include<iostream>
#include<cstdio>
using namespace std;
struct pp{
    int st,et;
    char name[17];
};

int main()
{
    struct pp *p,start,end;
    int day,n,cas,h,m,s;
    while(cin >> day)
    {
        while(day--)
        {
            scanf("%d%*c",&cas);
            p = new struct pp[cas];
            for(int i=0;i<cas;i++)
            {
                scanf("%s",p[i].name);
                scanf("%d:%d:%d",&h,&m,&s);
                p[i].st=h*3600+m*60+s;
                scanf("%d:%d:%d",&h,&m,&s);
                p[i].et=h*3600+m*60+s;
            }
            if(1==cas)
            {
                cout << p[0].name << " " << p[0].name << endl;
            }
                else
            {
                start = end = p[0];
                for(int i=1;i<cas;i++)
                {
                    if(p[i].st < start.st)
                        start = p[i];
                    if(p[i].et > end.et)
                        end = p[i];
                }
                cout << start.name << " " << end.name << endl;
            }
        }
    }
    return 0;
}
