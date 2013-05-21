#include <stdio.h>
int main()
{
	int a[5] = {1,2,3,4,5};
    int *ptr = (int *)(&a + 1);
    
    int *ptr1 = (int *)(&a + 5 * sizeof(int));
	int *ptr2 = (int *)(&a[0] + 1);
	int *ptr3 = (int *)(a + 1);
	int *ptr4 = (int *)(&a[0] + 1 * sizeof(int));
	
	printf("%d\n", *ptr); 
	printf("%d\n", *ptr1); 
	printf("%d\n", *ptr2); 
	printf("%d\n", *ptr3); 
	printf("%d\n", *ptr4); 
	return 0;
} 