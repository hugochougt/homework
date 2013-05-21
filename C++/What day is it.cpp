//求某天是星期几 

#include<cstdio>
using namespace std;

char *name[] = { "Monday", "Tuesday", "Wednesday",
"Thursday", "Friday", "Saturday", "Sunday" }; 

int main()
{
    int d, m, y, a;
    printf("Day: ");scanf("%d",&d);
    printf("Month: ");scanf("%d",&m);
    printf("Year: ");scanf("%d",&y);
    //1月2月当做前一年的13,14月
    if(m == 1 || m ==2 ) 
    {
        m +=12;
        y--;    
    }
    //判断是否在1752年9月3日之前
    if( ( y < 1752 ) || ( y == 1752 && m < 9 ) ||
        ( y == 1752 && m == 9 && d < 3 ) )
    {
        a = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 + 5) % 7;    
    }
    else
    {
        a = (d + 2 * m + 3 * (m + 1) / 5+ y + y / 4 - y / 100 + y / 400) % 7;
    }
    printf("It is a %s\n", name[a]);
    system("pause");
    return 0;
}
