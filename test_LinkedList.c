#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node
{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;
typedef PtrToNode Position;

/* 查找 */
Position Find(List L, ElementType X)
{
    Position p = L; /* p指向L的第1个结点 */
    while (p && p->Data != X)
        p = p->Next;
    return p;
}

List Read()
{
    int n, data;
    PtrToNode p, q, L = (PtrToNode)malloc(sizeof(struct Node));
    L->Next = NULL;
    scanf("%d", &n);
    for (; n; --n)
    {
        scanf("%d", &data);
        p = (PtrToNode)malloc(sizeof(struct Node));
        p->Data = data;
        p->Next = L->Next;
        L->Next = p;
    }
    return L;
}
void Pish(List L, ElementType X)
{
    
}

int Print(List L)
{
    int cnt = 0;
    List head = L->Next;
    while (head != NULL)
    {
        printf("%d ", head->Data);
        head = head->Next;
        ++cnt;
    }
    printf('\n');
    return cnt;
}

List Reverse(List L)
{
    List p = L, q;
    L = NULL;
    while (p)
    {
        q = p;
        p = p->Next;
        q->Next = L;
        L = q;
    }
    return L;
}

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}
