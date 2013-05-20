#include<stdio.h>
int main(void)
{
    int i,t,n,g,temp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        g=n%10;
        switch(g)
        {
            case 2:
                {
                    temp=n%4;
                    switch(temp){
                        case 0:g=6;break;
                        case 1:g=2;break;
                        case 2:g=4;break;
                        case 3:g=8;break;
                        default:break;
                        }
                    };break;
            case 3:{
                    temp=n%4;
                    switch(temp){
                        case 0:g=1;break;
                        case 1:g=3;break;
                        case 2:g=9;break;
                        case 3:g=7;break;
                        default:break;
                        }
                    };break;
            case 4:{
                    temp=n%2;
                    switch(temp){
                        case 0:g=6;break;
                        case 1:g=4;break;
                        default:break;
                        }
                };break;
            case 7:{
                    temp=n%4;
                        switch(temp)
                        {
                            case 0:g=1;break;
                            case 1:g=7;break;
                            case 2:g=9;break;
                            case 3:g=3;break;
                            default:break;
                        }
                    };break;
            case 8:{
                    temp=n%4;
                        switch(temp)
                        {
                            case 0:g=6;break;
                            case 1:g=8;break;
                            case 2:g=4;break;
                            case 3:g=2;break;
                            default:break;
                        }
                };break;
            case 9:{
                    temp=n%4;
                        switch(temp){
                            case 0:g=1;break;
                            case 1:g=9;break;
                            default:break;
                            }
                        };break;
            default:break;
        } 
        printf("%d\n",g);   
    }    
    return 0;
}
