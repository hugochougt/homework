#include<stdio.h>
#include<conio.h>
#include<math.h>
#define QUEENS 8

//记录解的序号的全局变量
int iCount = 0;
int Site[QUEENS];

//递归求解的函数
void Queen();

//输出一个解
void Output();

//判断第n个皇后放上去之后，是否有冲突
int IsValid(int n);

int main(){
	//从第0个开始递归试探 
	Queen(0);
	return 0; 
}

//递归放置第n个皇后
void Queen(int n){
	int i;
	//参数从0开始，等于8时便试出一个解，将它输出并回溯
	if(n == QUEENS){
		Output();
		return ;
	}
	
	//n还没有到8，在第n列的各个行上依次试探
	for(i = 1; i <= QUEENS; i++){
		//在该列的第i行上放置皇后
		Site[n] = i;
		if(IsValid(n)) 
			Queen(n + 1);
	} 
} 

//判断第n个皇后放上去之后，是否有冲突
int IsValid(int n){
	int i;
	//将第n个皇后的位置依次与前面n-1个皇后的位置比较
 	for(i = 0; i < n; i++){
	 	//两个皇后在同一行上，返回0
		if(Site[i] == Site[n]) 
			return 0;
		//两个皇后在同一对角线上，返回0
		if(abs(Site[i] - Site[n]) == n - i)
			return 0; 
 	}
 	//没有冲突，返回1
	 return 1; 
}

//输出一个解，即没有冲突的放置方案
void Output(){
	int i;
	//输出序号 
	printf("No.%-5d", ++iCount);
	//依次输出各个列上的皇后的位置，即所在的行数
	for(i = 0; i < QUEENS; i++)
		printf("%d ", Site[i]);
	printf("\n"); 
} 
