#include <stdio.h>

int fib(int n){
    int fn;
    if(n==1||n==2)
        fn=1;
    else
        fn=fib(n-1)+fib(n-2);
    return fn;
}

int main(int argc, char const *argv[])
{

    int n;
    while (scanf("%d", &n) != EOF) {
        printf("%d\n", fib(n));
    }
    return 0;
}