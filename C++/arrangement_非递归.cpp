#include<cstdio>
#include<cstring>
const int N = 9;
int n, out[N];
bool vis[N];

void dfs(int n) {
	int dep = 0;
	int j = 0;
	bool p = false;
	do{
		dep++;
		j = 0; p = false;
		do{
			j++;
			if(vis[j] == false){
				vis[j] = true;
				
			}
		}while();
	}while(dep > 0);
}

int main(){
	scanf("%d", &n);
	memset(vis, false, N);
	dfs(n);
	return 0;
}
