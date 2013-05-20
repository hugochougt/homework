#include<iostream>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;

const int N = 4;//种群规模
const int T = 100;//最大换代数
const double Pc = 0.4;//交叉率
const double Pm = 0.01;//变异率

int t;//代数计数器 

struct solution{
	int num;	//十进制数 
	char b[5];	//5位二进制数编码染色体
	int f;		//适应度 
	double p;	//选择概率
	double q;	//积累概率 
}s[N], next[N]; 

//交换字符 
void swap(char *a, char *b){
	char c = *a;
	*a = *b;
	*b = c;
}

//十进制转换为二进制 
void DtoB(int n, char str[]){
	int tmp, i = 0;
	memset(str, '0', 5);
	while(n){
		tmp = n % 2;
		str[i] = (char)tmp;
		n /= 2;
		i++;
	}
	
	//翻转 
	swap(&str[0], &str[4]);
	swap(&str[1], &str[3]);
	/*
	char c;
	c = s[0];
	s[0] = s[4];
	s[4] = c;
	c = s[1];
	s[1] = s[3];
	s[3] = c; 
	*/
}

//生成初始种群 
void init(){
	t = 1;
	srand((unsigned)time(0));
	
	for(int i = 0; i < N; i++){
		s[i].num = rand() % 32;
		DtoB(s[i].num, s[i].b);
		s[i].f = s[i].num * s[i].num;
	}
	
	int sumf = 0;//适应度总和 
	for(int i = 0; i < N; i++)
		sumf += s[i].f;
	
	double sumq = 0.0;//积累概率总和 
	for(int i = 0; i < N; i++){
		s[i].p = (double)s[i].f / sumf;
		sumq += s[i].p;
		s[i].q = sumq;
	} 
}

//产生0~1之间的随机数 
double randf() 
{ 
	return (double)(rand() % 1001) * 0.001; 
} 

//选择-复制 
void SelectNCopy(){
	double r;
	struct solution tmp[N];
	for(int i = 0; i < N; i++){
		r = randf();
		if(r < s[0].q)
			tmp[i] = s[0];
		else{
			int j;
			for(j = 1; j < N; j++){
				if(r > s[j-1].q && r < s[j].q)
					break;
			}
			tmp[i] = s[j];
		}
	}
	for(int i = 0; i < N; i++)
		next[i] = tmp[i];
}

//交叉 
void mate(){
	int a = 0, b = 0; 
	while(a == b){
		srand((unsigned)time(0));
		a = rand() % 4;
		b = rand() % 4;
	}
	int cb = rand() % 5;//交换的位数
	char ctmp;
	for(int i = 0; i < cb; i++)	 {
	//	swap(&s[a].b[4 - i], &next[b].num[4 - i]);
 		ctmp = s[a].b[4 - i];
		next[a].b[4 - i] = next[b].b[4 - i];
 		next[b].b[4 - i] = ctmp;
	}
}

//变异 
void variate(){
	int bits = int(5 * Pm);
	if(bits < 1)
		return ;
	else{
		int tmp;
		srand((unsigned)time(0));
		for(int i = 0; i < N; i++){
			tmp = rand() % 5;
			if(next[i].b[tmp] == '0')
				next[i].b[tmp] = '1';
			else
				next[i].b[tmp] = '0';
		}
	}
	return ;
}

//返回适应度最大的解 
struct solution maxf(struct solution ss[]){
	struct solution temp = ss[0];
	for(int i = 1; i < N; i++)
		if(ss[i].f > temp.f)
			 temp = ss[i];
 	return temp;
}

//进化，适者生存 
void evolve(){
	struct solution cm, nm;// cm：当前代适应度最大值，nm下一代适应度最大值
	cm = maxf(s) ;
	nm = maxf(next);
	if(nm.f > cm.f)
		for(int i = 0; i < N; i++)
			s[i] = next[i];
}

//用遗传算法求解答案 
void solve(){
	int mt;//交叉次数 
	while(t <= T){
		SelectNCopy();
	 	mt = (int)(5 * Pc) / 2;
	 	for(int i = 0; i < mt; i++)
			mate();
		//variate();
		evolve();
		t++;
	}
	struct solution max = s[0];
	for(int i = 0; i < N; i++)
		if(s[i].f > max.f)
			max = s[i];
	printf("求得的解是：%d\n", max.num);
	return ;
}

int main(){
	init();
	solve(); 
	system("pause");
	return 0; 
}
