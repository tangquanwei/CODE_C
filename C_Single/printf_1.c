#include <stdio.h>
#define PAGE 12345
#define NUM 1234.56789

int main()
{
    const double number = 1234.56789;
    printf("%f\n", number);
    printf("%e\n", number);
    printf("%E\n", number);
    printf("%4.5f\n", number);
    printf("%10.5f\n", number);
    printf("%10.5e\n", number);
    return 0;
}