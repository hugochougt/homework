#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int proc(int n);
int main(void)
{
    int t;
    while(cin >>t && t)
    {
        proc(t);
    }
}

int proc(int n)
{
    int arr[400], tmp[400];
    int num[4];
    int count,i,j,limit = 1;;

    memset(arr,0,sizeof(int)*400);
    arr[0] = 1;
    for(count=n+2;count <= 2*n; count++)
    {
        num[0] = count%10; num[1] = (count/10)%10; num[2] = count/100;
        memset(tmp, 0, sizeof(int)*400);
        for(i = 0; i< limit;i++)
        {
            for(j =0; j<3;j++)
            {
                tmp[i+j] += arr[i] * num[j];
            }
        }
        for(i= 0;i < limit+ 5;i++)
        {
            if( tmp[i] >=10)
            {
                tmp[i+1] += tmp[i] /10;
                tmp[i] %= 10;
            }
        }
        i = limit+ 6;
        while(tmp[i] == 0)
            i--;
        limit =i+1;
        for(i=0;i<limit;i++)
        {
            arr[i] = tmp[i];
        }/////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////
    }//////////////////////////////////////////////////////////////////////////

    for(count=2;count<=n;count++)
    {
        memset(tmp, 0, sizeof(int)*400);
        for(i = limit-2-(int)(log10(count));i >=0;i--)
        {
            int t = 0;
            int mul = 1;
            for(j=0;j<=(int)(log10(count)) +1;j++)
            {
                t += arr[i+j] * mul;
                mul *= 10;
            }
            tmp[i] += t/count;
            mul = 1; t%=count;
            for(j=0;j<= (int)(log10(count)); j++)
            {
                arr[i+j] = (t/mul)%10;
                mul *= 10;
            }
        }
        for(i=0;i< limit + 5;i++)
        {
            if(tmp[i] >=10)
            {
                tmp[i+1] += tmp[i]/10;
                tmp[i] %=10;
            }
        }
        i = limit +5;
        while(tmp[i] ==0)
            i--;
        limit = i+1;
        for(i=0;i<limit;i++)
        {
            arr[i] = tmp[i];
        }
    }

    i= limit-1;
    if(n==2)
    {
        arr[0]=2;
        i=0;
    }
    while(i>=0)
    {
        cout << (char)(arr[i--] + '0');
    }
    cout << endl;
    
}
