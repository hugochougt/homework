#include<stdio.h>
#include<string>
using namespace std;
const int VN = 1005;
double mp[VN][VN];
double dis[VN];
bool hash[VN];

int main(){
	int n, m, i, j, a, b, k;
	double _max = 0.0;
	while(scanf("%d", &n) != EOF){
		memset(mp, 0, sizeof(mp));
		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				scanf("%lf", &mp[i][j]);
		
		scanf("%d", &m);
		while(m--){
			scanf("%d%d", &a, &b);
			for(i = 1; i <= n; i++){
				hash[i] = false;
				dis[i] = 0;
			}
			dis[a] = 1.0;
			for(i = 1; i <= n; i++){
				_max = 0;
				for(j = 1; j <= n; j++){
					if(!hash[j] && dis[j] > _max){
						_max = dis[j];
						k = j;
					}
				}
				hash[k] = true;
				for(j = 1; j <= n; j++){
					if(mp[k][j] > 0 && dis[j] < dis[k] * mp[k][j])
						dis[j]  = dis[k] * mp[k][j];
				}
			}
			if(dis[b] == 0)
				printf("What a pity!\n");
			else
				printf("%.3lf\n", dis[b]);
		}
	}
	return 0;
}
