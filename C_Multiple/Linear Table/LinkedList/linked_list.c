#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
List MakeEmpty(int num, ElementType X)
{
    List L = (List)malloc(sizeof(struct Node));
    L->Data = X;
    L->Next = NULL;
    for (size_t i = 1; i < num; i++)
    {
        List p = (List)malloc(sizeof(struct Node));
        p->Data = X;
        p->Next = L->Next;
        L->Next = p;
    }
    return L;
}
ElementType FindKth(int k, List L)
{
    for (size_t i = 0; i < k && L; i++)
        L = L->Next;
    return L->Data;
}
int Find(ElementType X, List L){
    int cnt=0;
    while (L->Data!=X&&L)
    {
        L=L->Next;
        ++cnt;
    }
    return cnt==Length(L)?-1:cnt;

    
}
void Insert(ElementType X, int i, List L);
void Delete(int i, List L)
{
}
int Length(List L)
{
    int cnt = 0;
    while (L)
    {
        L = L->Next;
        ++cnt;
    }
    return cnt;
}
int main(int argc, char const *argv[])
{
    List L = MakeEmpty(10, 0);
    printf("%d\n", Length(L));
    printf("%d\n", FindKth(2,L));
    printf("%d\n", Find(1,L));
    return 0;
}
