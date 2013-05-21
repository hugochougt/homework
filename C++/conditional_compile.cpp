#include<cstdio>
//#define TWO 2

int main(){
	#ifdef ONE
		printf("1\n");
	#elif defined TWO
		printf("2\n");
	#else
		printf("3\n");
	#endif
	return 0;
}