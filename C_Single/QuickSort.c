#include <stdio.h>

int *QuickSort(int *a, int n)
{
    int less[n];
    int greater[n];
    int i, j, k;
    j = k = 0;
    if (n < 2)
        return a;
    else
    {
        pivot = a[0];
        for (i = 1; i < n; i++)
        {
            if (a[i] > a[0])
                greater[j++] = a[i];
            else
                less[k++] = a[i];
        }
    return QuickSort(less)
    }
}

int main()
{

    return 0;
}
 