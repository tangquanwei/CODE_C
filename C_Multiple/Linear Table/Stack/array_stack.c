#include "array_stack.h"
int main(int argc, char const *argv[])
{
    Sptr s=createStack(5);
    push(s,10);
    push(s,20);
    push(s,30);
    push(s,40);
    push(s,50);
    printf("pop : %d\n",pop(s));
    printf("pop : %d\n",pop(s));
    printf("pop : %d\n",pop(s));
    printf("pop : %d\n",pop(s));
    printf("pop : %d\n",pop(s));
    
    printf("pop : %d\n",pop(s));
    printf("pop : %d\n",pop(s));
    printf("pop : %d\n",pop(s));
    return 0;
}
