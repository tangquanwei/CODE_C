#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node
{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty();
ElementType FindKth(int k,List L);
int Find(ElementType X,List L);
void Insert(ElementType X,int i, List L);
void Delete(int i,List L);
void Clear(List L);
int Length(List L);


#endif