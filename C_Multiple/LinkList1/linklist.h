#ifndef _LINKLIST_H_
#define _LINKLIST_H_
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef int ElemType;      
/*int 可换为其他类型  */

typedef struct Node
{
    ElemType data;
    struct Node * next;
}Node;

typedef Node* LinkList;
/* 定义结构指针 */

/* 创建整张链表并随即赋值 */
void Init(LinkList *L, int n);

/* 查找L中的第i个节点的值，用e返回 */
bool Find(LinkList L, int i, ElemType* e);

/* 在第i个位置插入e */
bool Insert(LinkList *L, int i, ElemType e);

/* 删除第i的位置的节点并返回其值 */
bool Del(LinkList *L, int i, ElemType* e);

/* 将整张表置空 */
void Clear(LinkList *L);

#endif