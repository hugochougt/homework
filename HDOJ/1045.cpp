#include<stdio.h>
int n, cnt, ans;
char city[4][4];

bool isValid(int x, int y){
	city[x][y] = 'Y';
	bool flag = false;
	for(int j = 0; j < n; j++){
		if(city[x][j] == 'Y'){
			if(flag == true){
				city[x][y] = '.';
				return false;
			}
			flag = true;
		}
		if(city[x][j] == 'X')
			flag = false;
	}
	flag = false;
	for(int i = 0; i < n; i++){
		if(city[i][y] == 'Y'){
			if(flag == true){
				city[x][y] = '.';
				return false;
			}
			flag = true;
		}
		if(city[i][y] == 'X')
			flag = false;
	}
	return true;
}

void dfs(int r, int c){
	if(r == n){
		if(cnt > ans)
			ans = cnt;
		return ;
	}
	if(c == n){
		if(cnt > ans)
			ans = cnt;
		dfs(r+1, 0);
		return ;
	}
	for(int j = 0; j < n; j++){
		if(city[r][j] == '.' && isValid(r, j)){
			city[r][j] = 'Y';
			cnt++;
			dfs(r, j+1);
			city[r][j] = '.';
			cnt--;
		}
	}
	dfs(r+1, 0);
}

int main(){
	while(scanf("%d", &n) != EOF){
		if(!n) break;
		cnt = ans = 0;
		for(int i = 0; i < n; i++)
			scanf("%s", city[i]);
		dfs(0, 0);
		printf("%d\n", ans);
	}
	return 0;
}