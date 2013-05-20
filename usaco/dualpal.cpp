/*
  ID : chaos-z1
  PROG : dualpal
  LANG : C++
*/

#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

char code[20] = {'0', '1', '2', '3', '4', 
				 '5', '6', '7', '8', '9', };

bool IsPal(char *str)//是否是回文数 
{
	int i = 0;
	int j = strlen(str) - 1;
	if(j == 0)
		return true;
	for(; i < j; i++, j--)
	{
		if(str[i] != str[j])
			return false;
	}
	return true;
}

void Transform(int n, char *str, int b)
{
	int tmp, j = 0;
	while(n)
	{
		tmp = n % b;
		str[j] = code[tmp];
		n /= b;
		j++;
	}
	str[j] = '\0';
}

int main()
{
	freopen("dualpal.in","r",stdin);
    freopen("dualpal.out","w",stdout);
	int N, S;
	int CaseNum = 0;
	char string[25];
	cin >> N >> S;
	for(int i = S+1; CaseNum < N; i++)
	{
		int flag = 0;
		for(int j = 2; j <= 10; j++)
		{
			Transform(i, string, j);
			if(IsPal(string))
				flag++;
			if(flag >= 2)
				break;
		}
		if(flag >= 2)
		{
			cout << i << endl;
			CaseNum++; 
		}
	}
	//system("pause");
	return 0;
} 
