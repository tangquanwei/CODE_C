/*���b=0�����������a�������Լ����
���򣬼���a����b����������a=b,b=������
�ص���һ����
a   b   t
12  18  12
18  12  6
12  6   0
6   0
*/
#include <stdio.h>

int main() {
    int a,b,m,n,r;

    scanf("%d%d", &a,&b);
    m=a;
    n=b;
    do {
        r=m%n;
        m=n;
        n=r;
    } while (r != 0);
    printf("%d,%d", m,a*b/m);

    return 0;
}