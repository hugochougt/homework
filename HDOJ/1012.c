#include <stdio.h>

int main(void)
{
    int i;
    double e[10],f[10],q[10];
 
    f[0]=1; f[1]=1; e[0]=1;
    
    for(i=2;i<10;i++)
        f[i]=f[i-1]*i;
    
    for(i=0;i<10;i++)
    {
        q[i]=1/f[i];
        if(i>0)  
            e[i]=q[i]+e[i-1];  
    }	
    printf("n e\n- -----------\n");
    for(i=0;i<10;i++)
    {
        if(i<2) printf("%d %.0lf\n",i,e[i]);
        else if(i==2)   printf("%d %.1lf\n",i,e[i]);
        else    printf("%d %.9lf\n",i,e[i]);    
    }
    system("pause");
	return 0;
}
