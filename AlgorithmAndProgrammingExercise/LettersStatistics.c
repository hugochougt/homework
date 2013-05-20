//题1.统计字母的使用频率
 
#include<stdio.h>
#include<ctype.h>

//转换成小写字母
void lower(char *str){
	int i;
	for(i = 0; str[i] != '\0'; i++){
		if(isupper(str[i]))
			str[i] += 32;
	}
}

//统计各字母出现的频率
void count(char *str, int *arr){
	int i, tmp;
	for(i = 0; str[i] != '\0'; i++){
		tmp = str[i] - 'a';
		arr[tmp]++;
	}
}

//初始化字母顺序
void initArr(int *arr){
	int i;
	for(i = 0; i < 26; i++)
		arr[i] = i;
}

//交换两个数的值
void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//排序
void sort(int *_letters, int *arr){
	int i, j, k;
	for(i = 0; i < 25; i++){
		k = i; 
		for(j = i + 1; j < 26; j++){
			if(_letters[k] < _letters[j])
				k = j;
		}
		if(i != k){
			swap(&_letters[k], &_letters[i]);
			swap(&arr[k], &arr[i]);
		}
	}
}

void print(int *_letters, int *arr){
	int i;
	for(i = 0; i < 26; i++){
		printf("%c : %d\n", arr[i]+'a', _letters[i]);
	}
}

int main(){
	int letters[26] = {0};
	int Arr[26];	//保存字母的顺序
	char string[200];
	gets(string);
	lower(string);
	count(string, letters);
	initArr(Arr);
	sort(letters, Arr);
	print(letters, Arr);
	return 0;
}
