#include <stdio.h>

void f()
{
    printf("in f()\n");
}
void g()
{
    printf("in g()\n");
}
void h()
{
    printf("in h()\n");
}

void cal(int (*f)(int,int)){
    printf("%d",(*f)(2,3));
}
int plus(int a,int b){
    return a+b;
}
int minus(int a,int b){
    return a-b;
}
int main()
{

    int i = 0;
    void (*pa[])(void) = {f, g, h};
    scanf("%d", &i);

    if (i >= 0 && i < sizeof(pa) / sizeof(pa[0]))
        (*pa[i])();

    cal(plus);
    cal(minus);
    return 0;
}
