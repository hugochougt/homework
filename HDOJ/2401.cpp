#include<iostream>
using namespace std;
int main()
{
	int N, w, d, sel, sum;
	while(cin >> N >> w >> d >> sel)
	{
		sum = (N-1)*N*w/2;
		if(sum == sel)
			cout << N << endl;
		else
			cout << (sum-sel)/d << endl;
	}
	return 0;
}
