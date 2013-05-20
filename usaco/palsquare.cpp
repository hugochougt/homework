/*
  ID : chaos-z1
  PROG : palsquare
  LANG : C++
*/

#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

const int N = 300;
int num[N+1];
char code[20] = {'0', '1', '2', '3', '4', 
				 '5', '6', '7', '8', '9', 
				 'A', 'B', 'C', 'D', 'E',
				 'F', 'G', 'H', 'I', 'J' };
				 
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

bool IsPal(char *str)
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

int main()
{
	freopen("palsquare.in","r",stdin);
    freopen("palsquare.out","w",stdout);
	int B;
	char str[25], base[20];
	for(int i = 1; i <= N; i++)
		num[i] = i * i;
		
	cin >> B;
	for(int i = 1; i <= N; i++)
	{
		Transform(num[i], str, B);
		//printf("%s\n",str);
		if(IsPal(str))
		{
			Transform(i, base, B);
			for(int k = strlen(base)-1; k >= 0; k--)
				cout << base[k];
			cout << " " << str << endl;
		}
	}
	//system("pause");
	return 0;
}
