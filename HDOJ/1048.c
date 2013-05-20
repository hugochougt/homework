#include<stdio.h>
#include<string.h>
int main(void)
{
    char sign[11],data[101];
    int i;
    while(scanf("%s%*c",sign)!=EOF)
    {
        if(!strcmp("ENDOFINPUT",sign))    break;
        if(!strcmp("START",sign))
        {
            gets(data);
            for(i=0;data[i]!='\0';i++)
            {
                if(isupper(data[i]) && data[i]>='F')    
                    data[i]-=5;
                else if(isupper(data[i]))
                        data[i]+=21;
            }  
        } 
        if(!strcmp("END",sign))
            printf("%s\n",data);   
    }    
    return 0;
}
