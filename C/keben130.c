#include<stdio.h>
void main()
{
    int i;
    int f[40]={1,1};
    for(i=2;i<40;i++)
    f[i]=f[i-2]+f[i-1];
    for(i=0;i<40;i++){
    if(i%5==0) printf("\n");
    printf("%12d",f[i]);    
 }system("pause");
}
    
    
