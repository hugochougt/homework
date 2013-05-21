#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main(void)
{
    int n, m, i, j;
    int s[101];
    
    while (scanf("%d%d", &n, &m), m+n)
    {
        for (i = 0; i < n; i++)
            scanf("%d", s + i);
        for (i = 0; i < m; i++)
        {
            scanf("%d", s + n);
            for (j = 0; s[j] != s[n]; j++);
            if (j != n) s[j] = s[--n];
        }
        qsort(s, n, sizeof(int), cmp);
        for (i = 0; i < n; i++)
            printf("%d ", s[i]);
        printf(n ? "\n" : "NULL\n");
    }
    
    return 0;
}
