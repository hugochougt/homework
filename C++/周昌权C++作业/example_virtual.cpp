#include "iostream.h"
#include "string.h"
class CPerson
{
protected:
	char *name;
	char *phone;
public:
	CPerson (char *n, char *p)
	{
		name = new char[strlen(n)+1];
		strcpy (name, n);
		phone = new char[strlen(p)+1];
		strcpy (phone, p);
	}
	~CPerson ()
	{
		delete []name;
		delete []phone;
	}

	virtual void print ( );
};

void CPerson::print ( )
{
	cout << "Person" << endl;
	cout << "Name: " << name << endl;
	cout << "Phone: " << phone << endl;
}
class CStudent : public CPerson
{
protected:
	int studentID;
public:
	CStudent (char *n, char *p, int id) : CPerson (n, p), studentID(id)
	{ }
	void print ( );
};

void CStudent::print ( )
{
	cout << "Student" << endl;
	cout << "ID: " << studentID << endl;
	cout << "Name: " << name << endl;
	cout << "Phone: " << phone << endl;
}
class CTeacher : public CPerson
{
protected:
	int deptID;
public:
	CTeacher (char *n, char *p, int d ) : CPerson (n, p), deptID(d)
	{ }
	void print ( );
};

void CTeacher::print ( )
{
	cout << "Teacher" << endl;
	cout << "Dept: " << deptID << endl;
	cout << "Name: " << name << endl;
	cout << "Phone" << phone << endl;
}
int main ( )
{
	int i;
	CPerson **array = new CPerson *[3];
	
	array[0] = new CStudent("Joe", "555-1234", 3976);
	array[1] = new CTeacher("Daisy", "555-8909", 203);
	array[2] = new CPerson("Mandy", "555-3782");

	for ( i = 0; i < 3; i++ )
		array[i]->print();
		system("pause");
	return 0;
}
