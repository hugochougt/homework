/*
ID:chaos-z1
LANG:C++
TASK:friday
*/
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	FILE *fin, *fout;
	fin = fopen("friday.in", "r");
	fout = fopen("friday.out", "w");
	const int year = 365;
	int month[13] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
	int StartDay = 1;
	int weeks[7] = {0};
	int n, y, d, flag, TheYear, i;
	fscanf(fin, "%d", &n);
	for(y = 0; y < n; y++)
	{
		TheYear = 1900 + y;
		if( (TheYear % 400 == 0) || ((TheYear % 100 != 0) && (TheYear % 4) == 0) )
			flag = 1;
		else
			flag = 0;
		d = (13 + StartDay) % 7;
		weeks[d]++;
		d = (13 + StartDay + month[2]) % 7;
		weeks[d]++;
		for(i= 3; i <= 12; i++)
		{
			d = (month[i] + 13 + StartDay + flag) % 7;
			weeks[d]++;
		}
		StartDay = (year + flag + StartDay) % 7;
	}
	fprintf(fout, "%d", weeks[0]);
	for(i = 1; i < 7; i++)
		fprintf(fout, " %d", weeks[i]);
	fprintf(fout, "\n");
	return 0;
}
