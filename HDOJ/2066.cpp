#include<cstdio>
//#define clr(a, b) (memset(a, b, sizeof(a)))
using namespace std;
const int NV = 1002;
const int INF = 999999;
int graph[NV][NV];
bool hash[NV];
int len;
int main(){
	int x, y, time, tmp, min, k;
	int T, S, D;
	while(scanf("%d%d%d", &T, &S, &D) != EOF){
		//clr(graph, INF);
		for(int i = 0; i < NV; i++)
			for(int j = 0; j < NV; j++){
				graph[i][j] = INF;
			}
		len = 0;
		for(int i = 0; i < T; i++){
			scanf("%d%d%d", &x, &y, &time);
			if(graph[x][y] > time)
				graph[x][y] = graph[y][x] = time;
			if(x > len) len = x;
			if(y > len) len = y;
		}
		for(int i = 0; i < S; i++){
			scanf("%d", &tmp);
			graph[0][tmp] = 0;
		}
		for(int i = 0; i <= len; hash[i++] = false)	;
		for(int i = 1; i <= len; i++){
			min = INF;
			for(int j = 1; j <= len; j++){
				if(!hash[j] && graph[0][j] < min){
					min = graph[0][j];
					k = j;
				}
			}
			if(min == INF) break;
			hash[k] = true;
			for(int j = 1; j <= len; j++){
				if(!hash[j] && graph[0][j] > graph[0][k] + graph[k][j])
					graph[0][j] = graph[0][k] + graph[k][j];
			}
	}
		min = INF;
		for(int i = 0; i < D; i++){
			scanf("%d", &tmp);
			if(min > graph[0][tmp])
				min = graph[0][tmp];
		}
		/*
		for(int i = 0; i <= len; i++)
			for(int j = 0; j <= len; j++){
				printf("%d ", graph[i][j]);
				if(j == len)
					printf("\n");
			}
		*/
		printf("%d\n", min);
	}
	return 0;
}



