#include<iostream>
using namespace std;
const int INF = 9999999;
const int VN = 109;

int mp[VN][VN];
int dis[VN], n, m;
bool hash[VN];
int queue[1000001];

void SPFA(int s){
	memset(queue, 0, sizeof(queue));
	memset(hash, false, sizeof(hash));
	int front = 0, rear = 1, i, u;
	for(i = 1; i <= n; i++)	dis[i] = INF;
	dis[s] = 0;
	queue[front] = s;
	hash[s] = true;
	while(front < rear){
		u = queue[front];
		hash[u] = false;
		for(i = 1; i <= n; i++){
			if(dis[i] > dis[u] + mp[u][i]){
				dis[i] = dis[u] + mp[u][i];
				if(!hash[i]){
					hash[i] = true;
					queue[rear++] = i;
				}
			}
		}
		front++;
	}
}

int main(){
	int x, y, time, i, j, k;
	while(scanf("%d%d", &n, &m) != EOF){
		if(!n && !m) break;
		memset(mp, INF, sizeof(mp));
		for(i = 1; i <= m; i++){
			scanf("%d%d%d", &x, &y, &time);
			if(mp[x][y] > time)
				mp[x][y] = mp[y][x] = time;
		}
		SPFA(1);
		printf("%d\n", dis[n]);
	}
	return 0;
}
