/*
ID:chaos-z1
LANG:C++
TASK:gift1
*/
#include<stdio.h>
#include<string.h>
using namespace std;

char name[15][20] = {0};

int main()
{
	FILE *fin;
	FILE *fout;
	fin = fopen("gift1.in", "r");
	fout = fopen("gift1.out", "w");
	int NP, account, n, i, avr, NameIndex, j;
	char NameTmp[20] = {0};
	int data[15] = {0};
	fscanf(fin, "%d", &NP);
	for(i = 0; i < NP; i++)
	{
		fscanf(fin, "%s", name[i]);
	}
	for(i = 0; i < NP; i++)
	{
		fscanf(fin, "%s", NameTmp);
		fscanf(fin, "%d%d", &account, &n);
		if(!account)
			continue;
		NameIndex = 0;
		while(strcmp(name[NameIndex], NameTmp))	NameIndex++;
		if(!n)
		{
			data[NameIndex] += account;
			continue;
		}
		avr = account / n;
		data[NameIndex] += (account - avr * n);
		data[NameIndex] -= account;
		for(j = 0; j < n; j++)
		{
			fscanf(fin, "%s", NameTmp);
			NameIndex = 0;
			while(strcmp(name[NameIndex], NameTmp))	NameIndex++;
			data[NameIndex] += avr;
		}
	}
	for(i = 0; i < NP; i++)
		fprintf(fout, "%s %d\n", name[i], data[i]);
	fclose(fin);
	fclose(fout);
	return 0;
}
