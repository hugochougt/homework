#include<iostream>
using namespace std;

bool IsLeapYear(int y)  
{
	if( (0 == y % 4) && (0 != y % 100) || (0 == y % 400) )
		return true;
	else
		return false;
}

class date
{
public:
	date(int y, int m, int d);
	void Add_One_Day();
	void Input();
	void Output();
private:
	int year;
	int month;
	int day;
};

date::date(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}

void date::Input()
{
	cout << "Please input the year, month, day: ";
	cin >> year >> month >> day;
}

void date::Output()
{
	cout << year << "年" << month << "月"<< day << "日" << endl;
}

//加一天操作 
void date::Add_One_Day()
{
	if(day==31)
	{
		if(month==12)
		{
			year += 1;
			month = day = 1;
		}
		else
			month += 1;
	}
	else if(day==30)
		{
			switch(month)
			{
				case 4:
				case 6:
				case 9:
				case 11:month += 1;day =1;break;
				default:day += 1;break;
			}
		}
	else if(day==29)
		{
			if(2==month)
			{
				day =1;
				month += 1;
			}
			else
				day += 1;
		}
	else if(day==28)
		{
			if(2==month)
				if(IsLeapYear(year))
					day += 1;
				else
				{
					month += 1;
					day = 1;
				}
		}
	else 
		day += 1;
}

int main(void)
{
	date DATE(2010, 4, 13);

	DATE.Output();

	DATE.Add_One_Day();
	DATE.Output();

	DATE.Input();
	DATE.Output();
	DATE.Add_One_Day();
	DATE.Output();
	
    system("pause");
	return 0;
}
