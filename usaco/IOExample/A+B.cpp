/*
ID:chaos-z1
LANG:C++
TASK:A+B
*/
#include<fstream>
using namespace std;
int main()
{
	ifstream filein("A+B.txt");
	ofstream fileout("sum.txt");
	int a, b;
	while(filein >> a >> b)
		fileout << a+b << endl;
	return 0;
}
