#include <stdio.h>

int main() {
    int x, mask = 1, d, t;

    scanf("%d", &x);
    t = x;
    while (t > 9) {
        t /= 10;
        mask *= 10;
    }
    //printf("x=%d mask=%d\n", x, mask);
    do {
        d = x / mask;
        printf("%d", d);
        if (mask > 9) {
            printf(" ");
        }
        x %= mask;
        mask /= 10;
    } while (mask > 0);
    printf("\n");

    return 0;
}