#include<stdio.h>
#include <string>
#define N 13
using namespace std;


int main(){
	char map[N][N];
	int step[N][N];
	int row, col, ent, tmp, mark;
	while(scanf("%d%d", &row,&col) != EOF){
		if(!row&&!col) break;
		scanf("%d%*c", &ent);
		memset(step, 0, sizeof(step));
		memset (map, 0, sizeof(map) );
		tmp = col + 2;
		for(int i = 0; i < tmp; i++){
			map[0][i] = ' ';
			map[row+1][i] = ' ';
		}
		tmp = row + 2;
		for(int i = 0; i < tmp; i++){
			map[i][0] = ' ';
			map[i][col+1] = ' ';
		}
		for ( int i = 1; i <= row; i ++){
  			for ( int j = 1; j <= col; j ++ )
                  scanf ("%c", &map[i][j]);
     		getchar ();
       	}
       	int es = 1, ls= 0;
       	int i = 1, j = ent;
       	mark = 0;//tmp = 1;
       	while(map[i][j] != ' '){
		   if(step[i][j] != 0){
		   		//tmp = es;
	   			ls = step[i][j];
	   			mark = 1;
	   			break;
		   }
		   else{
		   		step[i][j] = es;
		   		switch(map[i][j]){
					case 'N':i--;break;
					case 'S':i++;break;
					case 'E':j++;break;
					case 'W':j--;break;   
		   		}
		   }
		   es++;
  		}
		if(mark == 0)
			printf("%d step(s) to exit\n", es-1);
		else
			printf("%d step(s) before a loop of %d step(s)\n", ls - 1, es - ls);
	}
}
