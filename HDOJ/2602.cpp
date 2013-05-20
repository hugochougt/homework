#include<iostream>
using namespace std;
template<class T> inline void checkmax(T &a,T b) {if(a < b) a = b;}
int main(){
	int T, N, V;
	__int64 w[1024], v[1024], dp[1024];
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &N, &V);
		memset(dp, 0, V);
		for(int i = 0; i < N; i++)
			scanf("%I64d", w+i);
		for(int i = 0; i < N; i++)
			scanf("%I64d", v+i);
		for(int i = 0; i < N; i++)
			for(int j = V; j >= v[i]; j--){
				checkmax(dp[j], dp[j-v[i]]+w[i]);
			}
		printf("%I64d\n", dp[V]);
	}
	return 0;
}
