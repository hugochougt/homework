#include<stdio.h>
//using namespace std; 
int a[30], b[30], n;
int g[42]={0};

void dfs(int k, int m){
	a[k] = m;
	if(k == n){
		if(!g[m+1])
			return ;
		printf("%d", a[1]);
		for(int i = 2; i <= n; i++)
			printf(" %d", a[i]);
		printf("\n");
	}
	for(int i = 2; i <= n; i++)
		if(b[i]&&g[m+i]){
			b[i] = 0;
			dfs(k+1, i);
			b[i] = 1;
		}
	return ;
}

int main(){
	int j = 1;
	//for(int i=0;i<42;i++) g[i]=0;
	g[2]=g[3]=g[5]=g[7]=g[11]=g[13]=g[17]=g[19]=g[23]=g[29]=g[31]=g[37]=g[41]=1;
	while(scanf("%d", &n) != EOF){
		for(int i = 0; i <= n; i++)
			b[i] = 1;
		printf("Case %d:\n", j++);
		dfs(1, 1);
		printf("\n");
	}
	return 0;
} 
