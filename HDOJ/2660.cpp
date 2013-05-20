#include<stdio.h>
#include<string.h>
int main(){
	int t, N, K, AW, cur, max;
	int v[42], w[42], i, j, val[22];
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &N, &K);
		for(i = 0; i < N; i++){
			scanf("%d%d", v+i, w+i);
			v[i+N] = v[i];
			w[i+N] = w[i];
		}
		scanf("%d", &AW);
		N *= 2;
		memset(val, 0, 22);
		for(i = 0; i < N; i++){
			cur = 0;
			for(j = 0; j < K; j++ ){
				cur += w[i+j];
				if(cur >= AW)
					break;
				val[i] += v[i+j];
			}
		}
		max = val[0];
		N /= 2;
		for(i = 1; i < N; i++)
			if(max < val[i])
				max = val[i];
		printf("%d\n", max);
	}
	return 0;
}
