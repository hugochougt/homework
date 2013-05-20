#include <stdio.h>
#include <string.h>

int main(void)
{
	char A[101]={0},B[101]={0};
    int i,j,tagA[2],tagB[2];
	while(gets(A),gets(B))
	{
	   for(i=0;A[i]=='0';i++)
            tagA[0]=i;
       for(i=100;A[i]=='0';i--)
            tagA[1]=i;
       for(i=0;B[i]=='0';i++)
            tagB[0]=i;
       for(i=100;B[i]=='0';i--)
            tagB[1]=i;
       for(i=tagA[0],j=tagB[0];(A[i]==B[i]) && (i<tagA[1]||j<tagB[1]);j++,i++);
       if(i==tagA[1]||j==tagB[1])
            printf("YES\n");
       else
            printf("NO\n");   
	}   
	return 0;
}
