// 题3.进制转换
 
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int menu(){
	int n;
	printf("欢迎使用进制转换程序！\n");
	printf("	1. 十进制\n");
	printf("	2. 二进制\n");
	printf("	3. 八进制\n");
	printf("	4. 十六进制\n");
	printf("	0. 退出\n");
	printf("请选择输入数据的进制：\n");
	while(true){
		scanf("%d", &n);
		switch(n){
			case 1:printf("请选择输入十进制数据：\n");
				return 10;
			case 2:printf("请选择输入二进制数据：\n");
				return 2;
			case 3:printf("请选择输入八进制数据：\n");
				return 8;
			case 4:printf("请选择输入十六进制数据：\n");
				return 16;
			case 0:printf("退出！\n");
				return 0;	
			default:printf("选择有误！请重新选择！"); 
		}
	}
}

//把r进制的数转换成十进制
int RtoD(int r, char *n){
	int res = 0, tmp, base = 1, len;
	len = strlen(n) - 1;
	while(len >= 0){
		if(isdigit(n[len]))
			tmp = n[len] - '0';
		else if(islower(n[len]))
			tmp = n[len] - 'a' + 10;
		else
			tmp = n[len] - 'A' + 10;
		res += tmp * base;
		base *= r;
		len--;
	}
	return res;
}

//十进制转换成对应的r进制
void DtoR(int n,int r)
{
    if(n)
    {
        DtoR(n/r,r);
        printf("%X", n%r);
    }    
}

void print(int n){
	printf("十进制：%d\n", n);
	printf("二进制：");
	DtoR(n, 2);
	printf("\n");
	printf("八进制：");
	DtoR(n, 8);
	printf("\n");
	printf("十六进制：");
	DtoR(n, 16);
	printf("\n");
}

//判断数是否合法
int judge(char *s, int n){
	int i, r = n - 1, tmp;
	for(i = 0; s[i] != '\0'; i++){
		if(isdigit(s[i]))
			tmp = s[i] - '0';
		else if(islower(s[i]))
			tmp = s[i] - 'a' + 10;
		else if(isupper(s[i])) 
			tmp = s[i] - 'A' + 10;
		else
			return 0;
		if(tmp > r)
			return 0;
	}
	return 1;
}

int main(){
	int N, num;
	char str[1000];
	while(N = menu(), N) {
		scanf("%s", str);
		if(!judge(str, N)){
			printf("输入数据有误！请重新输入！\n");
			continue;
		}
		num = RtoD(N, str);
		print(num);
	}
	return 0;
} 
