#include<stdio.h>
#include<string.h>
const int N = 10010;
struct incantation{
	char head, tail;
}ict[N];
int num;
bool flag, vis[N];

void dfs(int n){
	if(ict[n].tail == 'm'){
		flag = true;
		printf("Yes.\n");
		return ;
	}
	for(int j = 0; j < num; j++){
		if(ict[j].head == ict[n].tail && vis[j] == false){
			vis[j] = true;
			dfs(j);
			//vis[j] = false;
		}
	}
}

int main(){
	char str[N];
	num = 0;
	while(gets(str)){
		if(!strcmp(str, "0")){
			flag = false;
			memset(vis, false, N);
			for(int i = 0; i < num; i++){
				if(ict[i].head == 'b'){
					//vis[i] = true;
					dfs(i);
					//vis[i] = false;
					if(flag == true)
						break;
				}
			}
			if(flag == false)
				printf("No.\n");
			num = 0;
			flag = false;
		}
		else{
			ict[num].head = str[0];
			ict[num].tail = str[strlen(str)-1];
			num++;
		}
	}
	return 0;
}
