#include<iostream>
using namespace std;

//判断是否闰年 
bool IsLeapYear(int y)  
{
	if( ((0 == y % 4) && (0 != y % 100)) || (0 == y % 400) )
		return true;
	else
		return false;
}

//整数月份的天数 
int Nth_day(int m)
{
	int sum;

	switch(m)
	{
            case 1: sum=0;break;
            case 2: sum=31;break;
            case 3: sum=59;break;
            case 4: sum=90;break;
            case 5: sum=120;break;
            case 6: sum=151;break;
            case 7: sum=181;break;
            case 8: sum=212;break;
            case 9: sum=243;break;
            case 10: sum=273;break;
            case 11: sum=304;break;
            case 12: sum=334;break;
            default:break;
    }
	return sum;
}

int main(void)
{
	int year,month,day,date;
	
	cout << "请输入年 月 日 : "; 
	
	while(cin >> year >> month >> day)
	{
		date = day + Nth_day(month);
		
		if(IsLeapYear(year))     
			date++;          //闰年加一天 
			
		cout << "这一天属于该年的第" << date << "天" << endl;
		
		cout << "\n\n请输入年 月 日 : "; 
	}
	return 0;
}
