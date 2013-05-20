#include<iostream>
using namespace std;

const int VN = 202;
const int INF = 999999;

int map[VN][VN];
bool hash[VN];
int dis[VN];
int m, n;

void dijkstra(int s){
	int v, u, min, k;
	memset(hash, false, sizeof(hash));
	for(v = 0; v < n; v++)	dis[v] = INF;
	dis[s] = 0;
	for(v = 0; v < n; v++){
		min = INF;
		for(k = 0; k < n; k++){
			if(!hash[k] && dis[k] < min){
				min = dis[k];
				u = k;
			}
		}
		if(min == INF) break;
		hash[u] = true;
		for(k = 0; k < n; k++){
			if(!hash[k] && dis[k] > dis[u] + map[u][k])
				dis[k] = dis[u] + map[u][k];
		}
	}
}

int main(){
	int x, y, d;
	while(scanf("%d%d", &n, &m) != EOF){
		memset(map, INF, sizeof(map));
		while(m--){
			scanf("%d%d%d", &x, &y, &d);
			if(map[x][y] > d)
				map[x][y] = map[y][x] = d;
		}
		scanf("%d%d", &x, &y);
		dijkstra(x);
		if(dis[y] == INF)
			printf("-1\n");
		else
			printf("%d\n", dis[y]);
	}
	return 0;
}
