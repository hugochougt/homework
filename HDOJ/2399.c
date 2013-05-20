#include<stdio.h>
#include<string.h>
int main(void)
{
    char s[5000];
    int j,i,len,c,tag;
    double sum,ave;
    while(gets(s))
    {
        len = strlen(s);
        tag=1;
        for(i=0,sum=0,c=0;i<len;i++)
        {
            if(s[i]==' ')
               c++; 
            else if(s[i]=='A')
                    sum+=4;
            else if(s[i]=='B')
                    sum+=3;
            else if(s[i]=='C')
                    sum+=2;
            else if(s[i]=='D')
                    sum+=1;
            else if(s[i]=='F')
                    ;
            else
                {
                    tag=0;
                    printf("Unknown letter grade in input\n");
                    break;    
                }
        }   
        if(tag)
        {
            ave=sum/(c+1);
            printf("%.2lf\n",ave);    
        }     
    }    
    return 0;
}
