#include<cstdio>
using namespace std;

char *name[] = { "Monday", "Tuesday", "Wednesday",
"Thursday", "Friday", "Saturday", "Sunday" }; 

char *month[] = { "January", "February", "March",
"April", "May", "June", "July", "August",
"September", "October", "November", "December"};

int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//判断闰年
inline int leap(int year) 
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

//判断合法性
inline int legal(int day, int month, int year)
{
    if(month < 1 || month > 12)    
        return 0;
    if(month == 2)
        return day > 0 && day <= 28 + leap(year);
    return day > 0 && day <= days[month - 1];
}
int main()
{
    int d,m,y,a;
    while(scanf("%d%d%d",&m,&d,&y)!=EOF)
    {
        if(!m && !d && !y)    break;
        if(!legal(d, m, y))
            printf("%d/%d/%d is an invalid date.\n",m,d,y);
        else
        {
            int mm = m, dd = d, yy = y;
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
            printf("%s %d, %d is a %s\n",month[mm-1],dd,yy,name[a]);
        }
    }
    return 0;
}
