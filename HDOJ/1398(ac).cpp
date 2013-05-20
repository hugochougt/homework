//HDOJ_1398  Square Coins
#include <iostream>
using namespace std;

const int lmax=300;
int c1[lmax+1],c2[lmax+1];

int main(void)
{	
    int n,i,j,k;
	while (cin>>n && n!=0)
	{	
        for (i=0;i<=n;i++)
		{	
            c2[i]=0;         //由于对最后结果有影响的只是前N个，所以将其置0
            c1[i]=1;        //先生成一个函数，实质为1+x+x^2+x^3+……x^n
        }
        
		for (i=2;i<=17;i++)   //生成其余的函数对应1+x^i+x^2i+……
		{	
            for (j=0;j<=n;j++)              //二多项式相乘，先将第一个多项式逐项乘后一个多项式，
				for (k=0;k+j<=n;k+=i*i)     //如果二项相乘积大于x^n便可结束，道理如上一样，对最后结果无影响，
				{	                        //为什么使用k+=i*i,其实质就是一个生成函数：1+x^(i*i)+x^2(i*i)+……，
                    c2[j+k]+=c1[j];	        //没有的项系数为0,对于有效的项刚累加c1［j］，
                }                           //不是加1的原因为可能c1［］中不存在第j项，也就是说x^j的系数为0
                
			for (j=0;j<=n;j++)   //将结果保存在c1［］中，将c2［］清0，以便再循环使用
			{	
                c1[j]=c2[j];	
                c2[j]=0;
            }
		}
		cout<<c1[n]<<endl;
	}
	
	return 0;
}
