#include<stdio.h>
#include<string.h>
int n, max, map[16][16];
bool vis[16];

void dfs(int x, int num, int t){
	if(num > max) max = num;
	if(n == max) return ;
	for(int i = 1; i < n; i++){
		if(!vis[i] && map[x][i] >= t){
			vis[i] = true;
			dfs(i, num+1, map[x][i]);
			vis[i] = false;
		}
	}
}

int main(){
	while(scanf("%d", &n) != EOF){
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				scanf("%d", &map[i][j]);
		memset(vis, false, 16);
		max = 0;
		for(int i = 1; i < n; i++){
			vis[i] = true;
			dfs(i, 2, map[0][i]);
			vis[i] = false;
		}
		printf("%d\n", max);
	}
	return 0;
}
