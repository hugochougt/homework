#include <stdio.h>
#include <string.h>
#define NUM 999

int main(void)
{
	char A[NUM],B[NUM],T,i;
	void ADD(char str1[],char str2[]);
	while(scanf("%d",&T)!=EOF){
		for(i=0;i<T;i++)
			{
				scanf("%s %s",A,B);
				ADD(A,B);
			}	
	}    
	return 0;
}

void ADD(char str1[],char str2[]){
	int i,j,alen,blen,tag,s1[NUM],s2[NUM];
	
	alen=strlen(str1);
	blen=strlen(str2);
	
	for(i=0;i<NUM;i++)
		s1[i]=s2[i]=0;
		
	for(j=0,i=alen-1;i>=0;i--,j++)
		s1[j]=str1[i]-'0';
	for(j=0,i=blen-1;i>=0;i--,j++)
		s2[j]=str2[i]-'0';
		
	for(i=0;i<=NUM;i++)
		s1[i]+=s2[i];
	
	for(i=0;i<=NUM;i++)
		if(s1[i]>=10){
			s1[i]-=10;
			s1[i+1]++;
		}

	for(i=NUM;i>=0;i--)
		if(s1[i]!=0){
			tag=i;
			break;
		}
			
	for(i=tag;i>=0;i--)
			printf("%d",s1[i]);
}