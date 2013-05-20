#include<stdio.h>
/*下面是一个C程序，其想要输出20个减号，
 *不过，粗心的程序员把代码写错了，你需要
 *把下面的代码修改正确，不过，你只能增加
 *或是修改其中的一个字符，请你给出三种答
 *案。
 */
int main()
{
	int n = 20;
	int i;
	for(i = 0; i < n; i--){
	    printf("-");
	}
	system("pause");
	return 0;
}
