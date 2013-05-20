#include<stdio.h>
int main()
{
    typedef double *DOUBLE;
    DOUBLE p = NULL;
    double f = 12.3;
    double *q = &f;
    printf("p: %d %lf\n",sizeof(p), p);
    printf("f: %d %lf\n",sizeof(f), f);
    printf("q: %d %lf\n",sizeof(q), q);
    system("pause");
    return 0;
}
