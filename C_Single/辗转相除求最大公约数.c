/*如果b=0，计算结束，a就是最大公约数；
否则，计算a除以b的余数，让a=b,b=余数；
回到第一步。
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