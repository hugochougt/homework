#include<iostream>
using namespace std;
int main(void)
{
    int year;
    bool IsLeapYear;
    cout<<"Enter the year: ";
    
    while(cin>>year)
    {
        IsLeapYear=( (year%100!=0 && year%4==0) || (year%400==0) );
        if(IsLeapYear)  cout<<"Yes"<<endl;
        else    cout<<"No"<<endl;
        cout<<"Enter the year: ";
    }    
    return 0;
}
