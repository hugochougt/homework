/*
ID:chaos-z1
LANG:C++
TASK:test
*/
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main()
{
	ofstream fout("vans.out");
	ifstream fin("file.in");
	int a, b;
	fin >> a >> b;
	fout << a+b << endl;
	return 0;
}
