#include<iostream>
using namespace std;

const int VN = 1001;
const int INF = 999999;

int map[VN][VN];
bool hash[VN];
int dis[VN];
int m, n;

void dijkstra(int s){
	int v, u, min, k;
	memset(hash, false, sizeof(hash));
	for(v = 1; v <= n; v++)	dis[v] = INF;
	dis[s] = 0;
	for(v = 1; v <= n; v++){
		min = INF;
		for(k = 1; k <= n; k++){
			if(!hash[k] && dis[k] < min){
				min = dis[k];
				u = k;
			}
		}
		if(min == INF) break;
		hash[u] = true;
		for(k = 1; k <= n; k++){
			if(!hash[k] && dis[k] > dis[u] + map[u][k])
				dis[k] = dis[u] + map[u][k];
		}
	}
}

int main(){
	int d, x, y, time, w, start, min;
	while(scanf("%d%d%d", &n, &m, &d) != EOF){
		memset(map, INF, sizeof(map));
		while(m--){
			scanf("%d%d%d", &x, &y, &time);
			if(map[x][y] > time)
				map[y][x] = map[x][y] = time;
		}
		scanf("%d", &w);
		min = INF;
		while(w--){
			scanf("%d", &start);
			dijkstra(start);
			if(min > dis[d])	
				min = dis[d];
		}
		if(min == INF)	
			printf("-1\n");
		else
			printf("%d\n", min);
	}
}
