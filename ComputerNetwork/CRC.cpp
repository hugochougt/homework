/************************** 
模拟16位移位寄存器计算CRC 
**************************/
#include<iostream>
#define NBIT 16
#define NMESSAGE 100
using namespace std;

char XOR(char a, char b) {
	if(a == b)
		return '0';
	else
		return '1';
}

int main() {
	char message[NMESSAGE], shiftReg[NBIT + 1], xor0, xor1, xor2;
	int i, j;
	
	// 初始化移位寄存器 
	memset(shiftReg, '0', sizeof(shiftReg));
	shiftReg[NBIT] = '\0';
	// cout << shiftReg << endl;
	
	cout << "请输入报文：";
	cin >> message;
	
	for(i = 0; message[i] != '\0'; i++) {
		for(j = NBIT - 1; j >= 0; j--) {
			switch(j){
				case 15:
					xor0 = XOR(shiftReg[j], message[i]);
					shiftReg[15] = shiftReg[14];
					break;
				case 11:
					xor1 = XOR(xor0, shiftReg[10]);
					shiftReg[11] = xor1;
					break;
				case 4:
					xor2 = XOR(xor0, shiftReg[3]);
					shiftReg[4] = xor2;
					break;
				case 0:
					shiftReg[0] = xor0;
					break;
				default:
					shiftReg[j] = shiftReg[j - 1];
					break;
			}
		}
	}
	
	cout << shiftReg << endl;
	return 0;
}
