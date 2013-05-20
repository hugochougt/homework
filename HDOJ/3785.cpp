#include<cstdio>
#include<cstdlib>
typedef int (*fcmp)(const void *, const void *);
int cmp(const int *a, const int *b){
	return *b - *a; 
} 

void print(int a[], int n){
	printf("%d", a[0]);
	for(int i = 1; i < n; i++)
		printf(" %d", a[i]);
	printf("\n");
}

int main(){
	int n, m;
	int p[100010];
	while(scanf("%d%d", &n, &m) != EOF){
		if(!n && !m) break;
		for(int i = 0; i < n; i++)
			scanf("%d", p+i);
		qsort(p, n, sizeof(int), (fcmp)(cmp));
		if(m < n)
			print(p, m);
		else
			print(p, n);
	}
	return 0;
}
