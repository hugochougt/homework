#include<stdio.h>
#include<string.h>
const int N = 15;
int sum, n, out[N], arr[N], o;
bool used[N], flag;

void dfs(int cur, int s){
	if(s == sum){
		flag = false;
		printf("%d", out[0]);
		for(int k = 1; k < o; k++)
			printf("+%d",out[k]);
		printf("\n");
		
	}
	else{
		for(int k = cur; k < n; k++){
			out[o++] = arr[k];
			used[k] = true;
			dfs(k+1, s+arr[k]);
			used[k] = false;
			o--;
			k++;
			while(k < n && arr[k] == arr[k-1])
				k++;
			k--;
		}
	}
}

int main(){
	int i;
	while(scanf("%d%d", &sum, &n) != EOF){
		if(!sum && !n) break;
		for(i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		for(i = 0; i < n; i++)
			if(arr[i] <= sum)
				break;
		memset(used, false, sizeof(used));
		flag = true;
		o = 0;
		printf("Sums of %d:\n", sum);
		dfs(i, 0);
		if(flag)
			printf("NONE\n");
	}
	return 0;
}
