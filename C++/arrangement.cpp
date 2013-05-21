#include<cstdio>
#include<cstring>
const int N = 9;
int n, out[N];
bool vis[N];

void dfs(int depth){
	if(depth > n){
		printf("%d", out[1]);
		for(int i = 2; i <= n; i++)
			printf(" %d", out[i]);
		printf("\n");
		return ;
	}
	//vis[depth] = true;
	for(int i = 1; i <= n; i++){
		if(vis[i] == false){
			vis[i] = true;
			out[depth] = i;
			dfs(depth+1);
			vis[i] = false;
		}
	}
}

int main(){
	scanf("%d", &n);
	memset(vis, false, N);
	dfs(1);
	return 0;
}
