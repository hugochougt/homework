#include<iostream>
using namespace std;

const int VN = 1001;
const int INF = 999999;

int map[VN][VN];
bool hash[VN];
int dis[VN];
int m, n, s;

int dijkstra(){
	int v, u = -1, min, k;
	memset(hash, false, sizeof(hash));
	for(v = 0; v <= n; v++)	dis[v] = INF;
	dis[0] = 0;
	for(v = 0; v <= n; v++){
		min = INF;
		for(k = 0; k <= n; k++){
			if(!hash[k] && dis[k] < min){
				min = dis[k];
				u = k;
			}
		}
		hash[u] = true;
		if(hash[s])
			return dis[s];
		if(min == INF) 
			return -1;
		for(k = 0; k <= n; k++){
			if(!hash[k] && dis[k] > dis[u] + map[u][k] && map[u][k] != INF)
				dis[k] = dis[u] + map[u][k];
		}
	}
}

int main(){
	int x, y, time, w, start, ans;
	while(scanf("%d%d%d", &n, &m, &s) != EOF){
		memset(map, INF, sizeof(map));
		while(m--){
			scanf("%d%d%d", &x, &y, &time);
			if(map[x][y] > time)
				map[x][y] = time;
		}
		scanf("%d", &w);
		while(w--){
			scanf("%d", &start);
			map[0][start] = 0;
		}
		ans = dijkstra();
		printf("%d\n", ans);
	}
}
