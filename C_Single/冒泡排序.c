#include <stdio.h>
int main()
{
    int i, j, n, t;
    int a[100];
    printf("输入个数：");
    scanf("%d", &n);
    printf("输入要排序的数：\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 1; i < n; i++)
        for (j = 0; j < n - i; j++)
            if (a[j] > a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }

    printf("排序结果：\n");
    for (i = 0; i < n; i++)
        printf("%5d", a[i]);
}