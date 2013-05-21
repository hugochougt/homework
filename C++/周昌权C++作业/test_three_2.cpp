#include<iostream>
using namespace std;

class student
{
public:
	student();
	void data_Input();
	void data_Output();
	~student();
private:
	char name[20];
	int num;
	int age;
};

student::student()
{
    cout << "默认构造函数执行输入" << endl;
    cout << "请输入学生的姓名、学号、年龄："; 
	cin >> name >> num >> age;
}

void student::data_Input()
{
    cout << "成员函数执行输入" << endl;
    cout << "请输入学生的姓名、学号、年龄：";
	cin >> name >> num >> age;
}

void student::data_Output()
{
    cout << "成员函数执行输出" << endl;
	cout << "Name: " << name << endl;
	cout << "Number: " << num << endl;
	cout << "Age: " << age << endl;
}

student::~student()
{
    cout << "析构函数执行输出" << endl;
	cout << "Name: " << name << endl;
	cout << "Number: " << num << endl;
	cout << "Age: " << age << endl;
}

int main(void)
{
	student stud;
	
	stud.data_Input();
	
	stud.data_Output();
	
	return 0;
}
