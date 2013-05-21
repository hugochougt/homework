//LCS length
#include<iostream>
#include<cstring>
#define N 50
#define M 50

using namespace std;
int a[M+1][N+1];

int LCS(const char *s1, const char *s2)
{// s1:0...m, s2:0...n
    int m = strlen(s1), n = strlen(s2);
    int i, j;
    
    a[0][0] = 0;
    for(i = 1; i <= m; ++i)
        a[i][0] = 0;
    for(i = 1; i <= n; ++i)
        a[0][i] = 0;
        
    for(i = 1; i <= m; ++i)
        for(j = 1; j <= n; ++j)
        {
            if(s1[i-1]==s2[j-1])
                a[i][j] = a[i-1][j-1] + 1;
            else if(a[i-1][j] > a[i][j-1])
                a[i][j] = a[i-1][j];
            else
                a[i][j] = a[i][j-1];
        }
    return a[m][n];
}

int main()
{
    char str1[M], str2[N];
    while(1)
    {
        gets(str1);
        gets(str2);
        cout << LCS(str1,str2) << endl;
    }
    return 0;
}
