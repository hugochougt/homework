#include<iostream>
#define max 10000
using namespace std;
char str1[max], str2[max];
int a[max][max];

int lcs(char *s1, char *s2)
{// s1:0...m, s2:0...n
    int m=strlen(s1),n=strlen(s2);
    int i,j;
    a[0][0]=0;
    for(i=1;i<=m;i++)
        a[i][0]=0;
    for(i=1;i<=n;i++)
        a[0][i]=0;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(s1[i-1]==s2[j-1])
                a[i][j]=a[i-1][j-1]+1;
            else if(a[i-1][j]>a[i][j-1])
                a[i][j]=a[i-1][j];
            else
                a[i][j]=a[i][j-1];
    return a[m][n];
}
int main()
{
    while(cin >> str1 >> str2)
    {
        cout << lcs(str1,str2) << endl;    
    }
    return 0;
}
