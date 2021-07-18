#include <stdio.h>

typedef struct Node
{
    char data;
    struct Node *prev;
    struct Node *next;
} Node;

typedef Node *Linklist;

int main()
{
    char ch;
    Linklist p, r;
    Linklist L = (Linklist)calloc(sizeof(Node *), 1);
    L->next = L;
    L->prev = L;
    r = L;
    for (int i = 0; i < 3; i++)
    {
        p = (Linklist)malloc(sizeof(Node *));
        p->data = getchar();
        r->next = p;
        p->prev = r;
        r = p;
    }
    p->next = L;
    L->prev = p;
    //     for(;(ch=getchar)!='1';ch=getchar){
    //         printf("%d",p->data);
    //         p=p->prev;
    //     }
}