#include<iostream>
#include<string.h>

using namespace std;

class Person
{
public:
	Person(int n, char *str)
	{
		num = n;
		name = new char[sizeof(str)+1];
		strcpy(name, str);
	}
	void show_name()
	{
		cout << "Name: "<< name << endl;
	}
	void show_num()
	{
		cout << "Number: " << num << endl;
	}
private:
	char *name;
	int num;
};

class Student : public Person
{
public:
	Student(int n, char *str, int c, float s) : Person(n, str)
	{
		Class = c;
		score = s;
	}
	void show()
	{
		cout << "\n";
		show_name();
		show_num();
		cout << "Class: " << Class << endl;
		cout << "Score: " << score << "\n" <<endl;
	}
private:
	int Class;
	float score;
};

class Teacher : public Person
{
public:
	Teacher(int n, char *str, char *pro, char *dep) : Person(n, str)
	{
		pro_post = new char[sizeof(pro)+1];
		strcpy(pro_post, pro);
		department = new char[sizeof(dep)+1];
		strcpy(department, dep);
	}
	void show()
	{
		cout << "\n";
		show_name();
		show_num();
		cout << "Professional post: " << pro_post << endl;
		cout << "Department: " << department << endl;
	}
private:
	char *pro_post;
	char *department;
};

int main()
{
	Student Stu(9051109, "Hugo", 1, 88);
	Stu.show();
	Teacher Teach(1111, "Ann", "Doctor", "English");
	Teach.show();
	return 0;
}