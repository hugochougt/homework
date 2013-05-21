#include<stdio.h>
int main(){
	int n, c;
	while(scanf("%d", &n)!=EOF){
		if(!n) break;
		c = 0;
		while(n != 1){
			if(n%2) n = (3 * n +1) / 2;
			else n /= 2;
			c++;
		}
		printf("%d\n", c);
	}
	return 0;
}