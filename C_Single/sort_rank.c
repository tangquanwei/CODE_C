#include <stdio.h>

void sort_rank(int a[],int n);

int main(){
    int i, n;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort_rank(a,n);
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
    return 0;
}

void sort_rank(int a[],int n){
    int i,j;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (a[i] > a[j])
                a[i] ^= a[j] ^= a[i] ^= a[j];
}

