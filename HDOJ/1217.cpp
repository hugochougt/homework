#include<stdio.h>
#include<map>
#include<iostream>
#include<string>
using namespace std;

const int N = 31;

struct condition{
	int f, l;
	double v;
}a[N*N];

double s[N];

map<string, int>mm;

int n, m;

void Bellman_Ford(){
	int i, j;
	//bool flag = true;
	double tmp;
	memset(s, 0, sizeof(s));
	s[0] = 1.0;
	for(i = 0; i <= n /*&& flag*/; i++){
		//flag = false;
		for(j = 0; j < m; j++){
			tmp = s[a[j].f] * a[j].v;
			if(s[a[j].l] < tmp){
				s[a[j].l] = tmp;
				//flag = true;
			}
		}
	}
}

int main(){
	int i, CaseNum = 1;
	double tmp;
	char s1[50], s2[50];
	string str1, str2;
	while(scanf("%d", &n) != EOF){
		if(!n) break;
		mm.clear();
		for(i = 0; i < n; i++){
			scanf("%s", s1);
			str1 = s1;
			mm[str1] = i;
		}
		scanf("%d", &m);
		for(i = 0; i < m; i++){
			scanf("%s %lf %s", s1, &tmp, s2);
			str1 = s1;str2 = s2;
			a[i].f = mm[str1];
			a[i].l = mm[str2];
			a[i].v = tmp;
		}
		Bellman_Ford();
		printf("Case %d: ", CaseNum++);
		if(s[0] > 1.0)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
