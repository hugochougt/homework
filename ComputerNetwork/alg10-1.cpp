/************************** 
Dijkstra算法计算从指定源点到每个节点的最短路距离及下一跳路由表 
**************************/

#include <iostream>
#define INF 999999
#define VN 32
using namespace std;

int dist[VN][VN], n;
int length[VN], predecessor[VN], path[VN];
bool mark[VN];
	
void dijkstra(int s, int t) {
	int i, k ,min, tmp;

	for(i = 1; i <= n; i++) {
		length[i] = INF;
		predecessor[i] = -1;
		mark[i] = false;
	}
	length[t] = 0;
	mark[t] = true;
	k = t;
	do {
		for(i = 1; i <= n; i++) {
			if(dist[k][i] != 0 && mark[i] == false) {
				if(length[k] + dist[k][i] < length[i]) {
					predecessor[i] = k;
					length[i] = length[k] + dist[k][i];
				}
			}
		}
		k = 0;
		min = INF;
		for(i = 1; i <= n; i++) {
			if(mark[i] == false && length[i] < min) {
				min = length[i];
				k = i;
			}
		}
		mark[k] = true;
	}while(k != s);
	
	i = 0;
	k = s;
	do {
		path[i++] = k;
		k = predecessor[k];
	} while(k >= 0);
	printf("\n从源点到%d的", s);
	printf("下一跳站点为：");
	printf("%d\n", path[i - 2]);
}

int main() {
	int m, x, y, d, sp, i;
	memset(dist, INF, sizeof(dist));
	cout << "请输入图的节点数和边数：";
	cin >> n >> m;
	cout << "请输入图：\n";
	while(m--) {
		cin >> x >> y >> d;
		if(dist[x][y] > d) 
			dist[x][y] = dist[y][x] = d;
	}
	cout << "请输入源点：";
	cin >> sp;
	
	for(i = 1; i <= n; i++) {
		if(i != sp) {
			dijkstra(i, sp);
			cout << "最短路距离为：" << length[i] << endl;
		}
	}
	return 0;
}
