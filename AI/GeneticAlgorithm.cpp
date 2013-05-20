//题目: 利用遗传算法求解区间[0, 31]上的二次函数y = x*x的最大值
 
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;

int N = 4;//种群规模
int T = 100;//最大换代数
double Pc = 0.4;//交叉率
double Pm = 0.01;//变异率
int option = 0;

int t;//代数计数器 

bool flag = true;//标记是否是第一次计算结果 

struct solution{
	int num;	//十进制数 
	char b[5];	//5位二进制数编码染色体
	int f;		//适应度 
	double p;	//选择概率
	double q;	//积累概率 
}*s, *next;

void showCondition(){
	cout << "种群规模: " << N << endl;
	cout << "最大换代数: " << T << endl;
	cout << "交叉率: " << Pc << endl;
	cout << "变异率: " << Pm << endl << endl;
	if(!flag)
		system("pause");
}

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
}

//生成初始种群 
void init(){
	t = 1;
	srand((unsigned)time(0));
	if(flag){
		s = new struct solution[N];
		next = new struct solution[N];
		flag = false;
	}
	else{
		delete [] s;
		delete [] next;
	 	s = new struct solution[N];
		next = new struct solution[N];
	}
	
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
		a = rand() % N;
		b = rand() % N;
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
		variate();
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

// 计算答案 
void calculate(){
	init();
	solve();
}

void menu(){
	cout << "利用遗传算法求解区间[0, 31]上的二次函数y = x*x的最大值\n" << endl;
	cout << "初始状态：" << endl;
	showCondition();
	
	cout << endl;
	while(true){
		cout << "1>>>计算结果" << endl;
		cout << "2>>>设置种群规模" << endl;
		cout << "3>>>设置最大换代数" << endl;
		cout << "4>>>设置交叉率" << endl;
		cout << "5>>>设置变异率" << endl;
		cout << "6>>>显示各种参数" << endl;
		cout << "0>>>退出程序\n" << endl;
		
		cin >> option;
		
		switch(option){
			case 1:calculate();break;
			case 2:
					cout << "请输入新的种群规模值： ";
					cin >> N;break;
			case 3:
					cout << "请输入新的最大换代数： ";
					cin >> T;break;
			case 4:
					cout << "请输入新的交叉率： ";
					cin >> Pc;break;
			case 5:
					cout << "请输入新的变异率： ";
					cin >> Pm;break;
			case 6:showCondition();break;
			case 0:exit(0);break;
			default:cout << "选择错误！请重新选择！\n" << endl;break;
		}
	}
}

int main(){
	menu();
	return 0;
}
