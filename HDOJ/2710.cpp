#include <stdio.h>
#include <iostream>
using namespace std;
const int N = 20010;
int main()
{
	int Arr[N] = {0};
	int MaxIndex;
	int Max;
	int n, x;
	Arr[1] = 1;
	for(int i = 2; i < N; i++)
	{
		if(!Arr[i])
			for(int j = 1; i * j < N; j++)
				Arr[i*j] = i;
	}
	while(cin >> n)
	{
		Max = -1; MaxIndex = 1;
		while(n--)
		{
			cin >> x;
			if(Arr[x] > Max)
			{
				Max = Arr[x];
				//Max = Arr[x];
				MaxIndex = x;
			}
		}
		cout << MaxIndex << endl;
	}
	return 0;
}
