#include "linklist.h"

/* 创建整张链表并随即赋值 */
void Init(LinkList *L, int n)
{
    LinkList p;
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand() % 100 + 1;
        p->next = (*L)->next;
        (*L)->next = p; //x
    }
}

/* 查找L中的第i个节点的值，用e返回 */
bool Find(LinkList L, int i, ElemType *e)
{
    LinkList p = L;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        return false;
    *e = p->data;
    return true;
}

/* 在第i个位置插入e */
bool Insert(LinkList *L, int i, ElemType e)
{
    LinkList p = *L, q;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        return false;
    q = (LinkList)malloc(sizeof(Node));
    q->data = e;
    q->next = p->next;
    p->next = q;
    return true;
}

/* 删除第i的位置的节点并返回其值 */
bool Del(LinkList *L, int i, ElemType* e)
{
    LinkList p = *L, q;
    int j = 1;
    while (p->next && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p->next || j > i)
        return false;
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return true;
}

/* 将整张表置空 */
void Clear(LinkList *L)
{
    LinkList p = *L, q;
    int j = 1;
    while (!p)
    {
        q = p;
        p = p->next;
        free(q);
    }
    (*L)->next = NULL;
}
