#include <iostream>
#include <cstring>
#include <cstdlib>
#define N 50
using namespace std;

struct BigInt{
	char elem[N];
	int length;
};

void print(struct BigInt bigint)
{
	for(int i = 0; i < bigint.length; i++){
		cout << bigint.elem[i];
	}
	cout << endl;
}

void createRandomNum(struct BigInt &bigint)
{
	bigint.length = N;
	bigint.elem[0] = rand() % 5 + '1';
	for(int i = 1; i < bigint.length; i++)
		bigint.elem[i] =  rand() % 10 + '0';
}

void add(struct BigInt A, struct BigInt B, struct BigInt &C)
{
	int carry = 0, tmp;
	for(int i = N - 1; i >= 0; i--){
		tmp = (A.elem[i] - '0') + (B.elem[i] - '0') + carry;
		carry = tmp / 10;
		if(tmp > 9)
			tmp -= 10;
		C.elem[i] = tmp + '0';
	}
	C.length = N;
}

int main()
{
	BigInt bigintA, bigintB, bigintC;
	srand(unsigned(time(0)));
	createRandomNum(bigintA);
	print(bigintA);
	createRandomNum(bigintB);
	print(bigintB);
	add(bigintA, bigintB, bigintC);
	print(bigintC);
	
	return 0;
}
