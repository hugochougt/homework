#include<stdio.h>
//二分查找 
int BinarySearch(int arr[], int n, int target){
	int head = 0, tail = n - 1, mid;
	if(arr[head] == target)	return 0;
	while(head <= tail){
		mid = head + (tail - head) / 2;	//使用(head +tail)/2会有整数溢出的问题 
		if(target == arr[mid])
			return mid;
		if(arr[mid] > target)
			tail = mid - 1;
		else
			head = mid + 1;
	}
	return -1;
}

//测试代码 
/*
int main(){
	int a[10] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 100};
	int tar, index;
	scanf("%d", &tar);
	index = BinarySearch(a, 10, tar);
	if(index == -1)
		printf("没有此数\n");
	else
		printf("%d在第%d位",tar, index + 1);
	return 0;
} 
*/