/*
  ID : chaos-z1
  PROG : transform
  LANG : C++
*/
#include<stdio.h>
#include<string.h>
#include <iostream>
using namespace std;

char a[11][11], b[11][11], c[11][11];

bool Compare(char src[][11], char dst[][11], int n)
{
	for(int i = 0; i < n; i++)
		if(memcmp(src[i], dst[i], n))
			return false;
	return true;
}

void Transform(char src[][11],char dst[][11], int n, int k)
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			switch(k)
			{
				case 1:dst[i][j] = src[n-j-1][i];break;
				case 2:dst[i][j] = src[n-i-1][n-j-1];break;
				case 3:dst[i][j] = src[j][n-i-1];break;
				case 4:dst[i][j] = src[i][n-j-1];break;
			}
		
}

int main()
{
	freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);
	bool changed = false;
	int bng, end, n, res1 = 0, res2 = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int j = 0; j < n; j++)
	{
		cin >> b[j];
		if(memcmp(a[j], b[j], n))
			changed = true;
	}
	for(int k = 1; k <= 4; k++)
	{
		Transform(a, c, n, k);
		if(Compare(b, c, n))
			return cout << k << endl, 0;
	}
	for(int k = 1; k <= 3; k++)
	{
		Transform(c, a, n, k);
		if(Compare(a, b, n))
			return cout << "5" << endl, 0;
	}
	puts(changed ? "7" : "6");
	return 0;
}
