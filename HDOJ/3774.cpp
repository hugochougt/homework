#include<stdio.h>
#include<stdlib.h>
struct run{
	int x, r;
}runner[105];
int cmp(const void *a, const void *b){
	struct run *c=(run *)a;
	struct run *d=(run *)b;
	return c->r - d->r;
}

int main(){
	int t, n, m, flag;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i++)
			scanf("%d%d", &runner[i].x, &runner[i].r);
		qsort(runner, n, sizeof(run), cmp);
		flag = 1;
		for(int i = 1; i < n; i++)
			if(runner[i].x > runner[i-1].x)
			{
				flag = 0;
				break;
			}
		if(flag) printf("YES\n");
		else	printf("NO\n");
	}
	return 0;
}
