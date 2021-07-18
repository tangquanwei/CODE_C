#include "linklist.h"
#include <stdio.h>

int main()
{
    LinkList *List;
    ElemType *e;

    Init(List, 10);
    Find(List, 1, e);
    printf("%d\n", *e);

    Insert(&List, 1, 255);
    Find(List, 1, e);
    printf("%d\n", *e);

    Del(List, 1, e);
    printf("%d\n", *e);

    Find(List, 1, e);
    printf("%d\n", *e);

    printf("Input any to exit");
    getchar();

    return 0;
}