#include<iostream>
using namespace std;
class Date
{
public:
    Date(){};
    Date(int y,int m,int d);
    Date(Date &D);
    ~Date(){};
    friend ostream & operator << (ostream &out,const Date &D);
    bool IsLeapYear();
    void ChangeDate(int ,int , int );
private:
    int year,month,day;
};

Date::Date(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;    
}
Date::Date(Date &D)
{
    year = D.year;
    month = D.month;
    day = D.day;
}
ostream & operator << (ostream &out, const Date &D)
{
    cout << D.year << "/" << D.month << "/" << D.day ;
    return out;
}
bool Date::IsLeapYear()
{
    if(year%400==0||(year%4==0&&year%100!=0))
        cout << year << " is a leap year." << endl;
    else
        cout << year << " is not a leap year." << endl;
}
void Date::ChangeDate(int y, int m, int d)
{
    year = y;
    month = m;
    day = d; 
}
int main()
{
    Date d1(2010,6,20),d2(2000,1,1),d3(1989,2,25);
    Date d4(d2);
    cout << d1 << "\n" << d2 << endl;
    d2.IsLeapYear();
    cout << d3 << endl;
    d3.ChangeDate(1989,12,29);
    cout << d3 << endl;
    cout << d4 << endl;
    system("pause");
    return 0;
}
