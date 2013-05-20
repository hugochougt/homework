#include<stdio.h>
#include<stdlib.h>
typedef int (*fcmp)(const void *, const void *);
int cmp(const int *a, const int *b){
	return *a - *b;
}

int main(){
	int tri[3], t, tmp;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		for(int j = 0; j < 3; j++)
			scanf("%d",tri+j);
		qsort(tri, 3, sizeof(int), (fcmp)cmp);
		tmp = tri[0]*tri[0] + tri[1]*tri[1] - tri[2]*tri[2];
		if(!tmp)
			printf("Case %d: Right triangle\n", i);
		else if(tmp < 0)
			printf("Case %d: Obtuse triangle\n", i);
		else
			printf("Case %d: Acute triangle\n", i);
	}
	return 0;
}
