#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void FindNum();
void FindRoot();
void Detective();
void Double_ball();
void Diamond();

int main(void)
{
	int sel;
	printf("1.FindNum\n");
	printf("2.FindRoot\n");
	printf("3.Detective\n");
	printf("4.Double_ball\n");
	printf("5.Diamond\n");
	printf("6.Goodbye!\n");
	printf("Input your selection:");

	while(scanf("%d",&sel)!=EOF){
		switch(sel)
		{
			case 1:FindNum();break;
			case 2:FindRoot();break;
			case 3:Detective();break;
			case 4:Double_ball();break;
			case 5:Diamond();break;
			case 6:printf("Goodbye!\n");exit(0);
			default:printf("Input Error!\n");break;
		}
	}
	return 0;
}

void FindNum(){
	int i;
	for(i=0;i<10;i++)
	{
		if((30+i)*6237==(i*10+3)*3564)
		{
			printf("The answer is %d\n",i);
			printf("3%d*6237=%d3*3564\n",i,i);
			break;
		}
	}
	return ;
}

void FindRoot(){
	double a,b,c;
	printf("Input a,b,c\n");
	scanf("%lf",&a);
	scanf("%lf",&b);
	scanf("%lf",&c);
	
	if(a==0.0)
	{
		if(b==0.0)
			printf("No answer due to input error\n");
		else
			printf("The sigle root is %lf\n",-c/b);
	}
	else{
		double disc,twoa,term1,term2;
		disc=b*b-4.0*a*c;
		twoa=2*a;
		term1=-b/twoa;
		term2=sqrt(fabs(disc))/twoa;
		if(disc<0.0)
			printf("Complex root:\n real part=%lf,imag part=%lf\n",term1,term2);
		else
			printf("Real root:\n root1=%lf,root2=%lf\n",term1+term2,term1-term2);
	}
	return ;
}

void Detective(){
	int a,b;
	double G;
	for(a=0;a<10;a++)
		for(b=0;b<10;b++){
			G=sqrt(a+a*10+b*100+b*1000);
			if(G==(int)G)
				printf("The license plate is 31%d%d%d%d\n",a,a,b,b);
		}
	return ;
}

void Double_ball(){
	int i;
	srand((unsigned)time(0));
	for(i=0;i<7;i++)
		printf("%-4d",rand()%34+1);
	printf("%-4d\n",rand()%7+1);
	return ;
}

void Diamond(){
	printf("   *\n");
	printf("  ***\n");
	printf(" *****\n");
	printf("*******\n");
	printf(" *****\n");
	printf("  ***\n");
	printf("   *\n");
	return ;
}