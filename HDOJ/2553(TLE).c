#include<stdio.h>
#include<math.h>

int Site[11];
int N;
int iCount;

void Queen(int n){
	int i;
	if(n == N){
		iCount++;
		return ;
	}
	else{ 
		for(i = 1; i <= N; i++){
			Site[n] = i;
			if(IsValid(n))
				Queen(n+1);
		}
	} 
}

int IsValid(int n){
	int i;
	for(i = 0; i < n; i++){
		if(Site[i] == Site[n] || abs(Site[i] - Site[n]) == n - i)
			return 0;
	}
	return 1;
}

int main(){
	while(scanf("%d", &N) != EOF){
		if(!N) break;
		iCount = 0;
		Queen(0);
		printf("%d\n", iCount);
	}
	return 0;
} 
