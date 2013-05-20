/*
ID:chaos-z1
LANG:C++
TASK:beads
*/
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{
	FILE *fin, *fout;
	char beads[800] = {0}, NowChar = 0;
	int max = 0, bl = 0, br = 0, w = 0, i, n;
	fin = fopen("beads.in", "r");
	fout = fopen("beads.out", "w");
	fscanf(fin, "%d%*c%s", &n, beads);
	memcpy(beads+n, beads, n);
	for(i = 0; beads[i] && max < n; i++)
	{
		if(beads[i] == 'w')
			w++, br++;
		else if(NowChar != beads[i])
		{
			if(max < bl + br)
				max = bl + br;
			bl = br - w;
			br = w + 1;
			w = 0;
			NowChar = beads[i];
		}
		else
		{
			br++;
			w = 0;
		}
	}
	if(bl + br > max)
		max = bl + br;
	fprintf(fout, "%d\n", max>n ? n : max);
	return 0;
}
