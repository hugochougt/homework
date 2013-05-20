#include<iostream>
using namespace std;
const int VN = 110;
const int MAX = 999999;
int mp[VN][VN];
int dis[VN];
bool hash[VN];
int main(){
	int n, m, x, y, time, i, j, min, k;
	while(scanf("%d%d", &n, &m) != EOF){
		if(!n && !m) break;
		memset(mp, MAX, sizeof(mp));
		for(i = 1; i <= m; i++){
			scanf("%d%d%d", &x, &y, &time);
			if(mp[x][y] > time)
				mp[x][y] = mp[y][x] = time;	//可能要加入if()语句
		}
		for(i = 0; i <= n; i++){
			hash[i] = false;
			mp[i][i] = 0;
		}
		for(i = 2; i <= n; i++){
			dis[i] = mp[1][i];
		}
		dis[1] = 0;hash[1] = true;
		for(i = 2; i <= n; i++){
			min = MAX;
			k = 1;
			for(j = 2; j <= n; j++){
				if(!hash[j] && dis[j] < min){
					min = dis[j];
					k = j;
				}
			}
			if(min == MAX) break;
			hash[k] = true;
			for(j = 2; j <= n; j++){
				if(!hash[j] && dis[j] > dis[k] + mp[k][j] && mp[k][j] < MAX)
					dis[j] = dis[k] + mp[k][j];
			}
		}
		printf("%d\n", dis[n]);
	}
	return 0;
}
