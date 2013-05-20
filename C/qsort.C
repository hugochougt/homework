#include <stdlib.h> 
#include <stdio.h> 

// 定义函数指针
typedef int (*fcmp)(const void *, const void *);

// 定义要在其中查找的数组及元素

int array[] = {21, 5, 12, 68, 56, 43, 10}; 

/* 用户自己定义的比较函数，转化类型后作为lsearch中的
   int (*fcmp)(const void *, const void *) 参数*/

int numcmp (const int *p1, const int *p2) 
{ 
   int value;

   // 比较
   value = *p1-*p2;

   if (value==0)
	   return 0;
   else if (value<0)
	   return -1;
   else
	   return 1;

} 

int main(void) 
{ 
   int i;
  
   // 输出排序前的数组
   printf("Before sorted,the array is:\n");

   for (i=0;i<7;i++)
	   printf("%6d",array[i]);
   printf("\n");

   // 使用qsort进行排序
   qsort(array, 7, sizeof(int), (fcmp)(numcmp)); 

   
   // 输出排序后的结果
   printf("After sorted,the array is:\n");

   for (i=0;i<7;i++)
	   printf("%6d",array[i]);

   printf("\n");

   system("pause");
   return 0; 

} 

