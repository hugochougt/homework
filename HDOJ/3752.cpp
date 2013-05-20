#include<stdio.h>
int main(){
	int t, m, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &m, &n);
		if(m%2==1 || n>m/2)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}