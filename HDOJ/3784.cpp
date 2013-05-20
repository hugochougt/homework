#include<stdio.h> 
int main(){
	int n, arr[502], cn, out[502];
	while(scanf("%d", &n) != EOF){
		if(!n) break;
		cn = 0;
		for(int i = 0; i < n; i++){
			scanf("%d", arr+i);
			if(arr[i]%2 == 1){
				out[cn] = arr[i];
				cn++;
			}
		}
		cn--;
		printf("%d", out[cn]);
		for(int i = cn-1; i >= 0; i--)
			printf(" %d", out[i]);
		printf("\n");
	}
	return 0;
} 