#include <stdio.h>          //使用动态数组,实现Fibonacci数列. 
#include <stdlib.h>         //该数列为a[n]=a[n-1]+a[n-2],其中a[0]=a[1]=1. 

int main(void)
{
    int i,num;
    long *f,*tmp;
    
    printf("请输入Fibonacci数列的个数: ");
    scanf("%d",&num);
    printf("\n");
    
    f=(long*)calloc(num,sizeof(int));
    if(f==NULL)
    {
        printf("没有内存可以分配!\n");
        return 0;
    }    
    
    f[0]=f[1]=1;            //或者写成 *f=*(f+1)=0. 
    
    for(i=2;i<num;i++)
        f[i]=f[i-1]+f[i-2];         //或者写成*(f+i)=*(f+i-1)+*(f+i-2) 
    
    for(tmp=f;tmp<f+num;tmp++)           //tmp++使tmp指向下一个单元, 
        if((tmp-f+1)%5!=0)               //而不是下一个字节,因为tmp指向的 
            printf("%10ld",*tmp);        //单元类型是long型. 
        else
            printf("\n");
    
    free(f);
    system("pause"); 
    return 0;    
}
