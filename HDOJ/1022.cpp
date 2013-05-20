#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int n, flag[20], top;
	int flagi, ini, outi;
	char in[10], out[10];
	char stack[100];
	while(cin >> n >> in >> out)
	{
		top = -1;
		flagi = ini = outi = 0;
		while(ini < n + 1 && outi < n)
		{
			if(stack[top] == out[outi] && top != -1)
			{
				top--;
				flag[flagi++] = 0;
				outi++;
			}
			else
			{
				top++;
				flag[flagi++] = 1;
				stack[top] = in[ini];
				ini++;
			}
		}
		if(flagi != 2 * n)
			cout << "No." << endl;
		else
		{
			cout << "Yes." << endl;
			for(int i = 0; i < n*2; i++)
			{
				if(flag[i])
					cout << "in" << endl;
				else
					cout << "out" << endl;
			}
		}
		cout << "FINISH" << endl;
	}
	return 0;
}
