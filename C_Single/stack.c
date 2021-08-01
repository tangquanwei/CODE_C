#include <stdio.h>
int *f();
void g();
int main()
{

    int *p = f();
    printf("*p = %d\n", *p);
    g();
    printf("*p = %d\n", *p);

    return 0;
}
int *f()                                          
{
    int i = 12;
    return &i;
}
void g()
{
    int k = 24;
    printf("k = %d\n", k);
}