#include<stdio.h>
#include<string.h>
const int N = 23;
int max;
bool flag[N][N];
char map[N][N];
int dir[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

void dfs(int x, int y){
	for(int i = 0; i < 4; i++){
		if(map[x + dir[i][0]][y + dir[i][1]] == '.' && !flag[x + dir[i][0]][y + dir[i][1]]){
			max++;
			flag[x + dir[i][0]][y + dir[i][1]] = true;
			dfs(x + dir[i][0], y + dir[i][1]);
		}
	}
}

int main(){
	int w, h;
	int xx, yy;
	while(scanf("%d%d%*c", &w, &h) != EOF){
		if(!w && !h) break;
		memset(flag, false, sizeof(flag));
		memset(map, '#', sizeof(map));
		for(int i = 1; i <= h; i++){
			for(int j = 1; j <= w; j++){
				scanf("%c", &map[i][j]);
				if(map[i][j] == '@'){
					xx = i;
					yy = j;
				}
			}
			getchar();
		}	
		max = 1;
		flag[xx][yy] = true;
		dfs(xx, yy);
		printf("%d\n", max);
	}
	return 0;
}
