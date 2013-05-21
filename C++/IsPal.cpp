#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

bool IsPal(char *str)
{
	int i = 0;
	int j = strlen(str) - 1;
	if(j == 1)
		return true;
	for(; i < j; i++, j--)
	{
		if(str[i] != str[j])
			return false;
	}
	return true;
}

int main()
{
	char str[20];
	cin >> str;
	if(IsPal(str))
		cout << "Y" << endl;
	else
		cout << "N" << endl;
}
