/* 7. Derived Classes and Inheritance */
#include <iostream>
using namespace std;
class Person
{
	private:
		char *name,*nationality;
		char sex;		
	public:
		Person(char *n, char s, char *nat = "P.R.C"):sex(s)
		{
			name = new char[sizeof(n)+1];
			strcpy(name, n);
			nationality = new char[sizeof(nat)+1];
			strcpy(nationality, nat);	
		}
		void printName(){cout << name;}
		void printNationality(){cout << nationality;}

};

class Student:public Person
{
	private:
		char *id;
		int month, day, year;
		int credits;
		float gpa;
	public:
		Student(char *n, char s = '\0', char *i = ""):Person(n, s)
		{
			id = new char[sizeof(i)+1];
			strcpy(id, i);
			credits = 0;	
		}
		void setDOM(int m, int d, int y)
		{
			month = m;
			day = d;
			year = y;	
		}
		void printDOM()
		{
			cout << month << "," << day << "," << year << endl;
		}
		
};
void main()
{
    Student x("Hugo Chou", 'M', "09051109");
    x.setDOM(9, 18, 2009);
    x.printName();
    cout << "\n\tMatriculated:";
    x.printDOM();
    cout << endl;
}