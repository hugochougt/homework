//²»¶ÔµÄ 
#include<cstdio>
#include<cstring>
using namespace std;

const int N = 50;
const int M = 50;

int b[M+1][N+1],c[M+2][N+2];
int lenX,lenY;
char X[M+1], Y[N+1];

void LCS_length(char *X, char *Y)
{
    //lenX = strlen(X);
    //lenY = strlen(Y);
    c[0][0]=0;
    for(int i = 1; i <= lenX; ++i)
        c[i][0] = 0;
    for(int i = 0; i <= lenY; ++i)
        c[0][i] = 0;
        
    for(int i = 1; i <= lenX; ++i)
        for(int j = 1; j <= lenY; ++j)
        {
            if(X[i-1] == Y[j-1])
            {
                c[i][j] = c[i-1][j-1] + 1;
                b[i-1][j-1] = -1;
            }
            else if(c[i-1][j] > c[i][j-1])
                {
                    c[i][j] = c[i-1][j];
                    b[i-1][j-1] = -2;
                }
            else
            {
                c[i][j] = c[i][j-1];
                b[i-1][j-1] = -4;
            }
        }
}

void print_LCS(int i, int j)
{
    if(i == 0 || j == 0)
        return ;
        
    if(b[i][j] == -1)
    {
        print_LCS(i - 1, j - 1);
        printf("%c", X[i]);
    }
    else if(b[i][j] == -2)
        {
            print_LCS(i - 1, j);
        }
    else
        print_LCS(i, j - 1);
}

int main()
{
    while(1)
    {
        gets(X);
        gets(Y);
        lenX = strlen(X);
        lenY = strlen(Y);
        
        printf("lenX:%d lenY:%d\n",lenX,lenY);
        
        LCS_length(X, Y);
        
        print_LCS(lenX, lenY);
        printf("\n");
    }
    return 0;
}
