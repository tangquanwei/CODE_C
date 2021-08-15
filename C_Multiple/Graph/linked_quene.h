#if !defined(__LINKED_QUENE_H__)
#define __LINKED_QUENE_H__
#define ERROR NULL
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 链表前面删除,后面加入
typedef int ElementType;
typedef struct Node* PtrToNode;
struct Node /* n个 */
{
	ElementType Data;
	PtrToNode Next;
};
typedef PtrToNode Position;

struct QNode /* 一个 */
{
	int MaxSize;
	Position Rear;	/* 指向队尾结点 */
	Position Front; /* 指向队头结点 */
};
typedef struct QNode* Queue;

bool IsEmpty(Queue Q) {
	return (Q->Front == NULL);
}

ElementType DeleteQ(Queue Q) {
	Position FrontCell;
	ElementType FrontElem;

	if (IsEmpty(Q)) {
		printf("队列空");
		return ERROR;
	}
	else {
		FrontCell = Q->Front;
		if (Q->Front == Q->Rear)	   /* 若队列只有一个元素 */
			Q->Front = Q->Rear = NULL; /* 删除后队列置为空 */
		else
			Q->Front = Q->Front->Next;
		FrontElem = FrontCell->Data;

		free(FrontCell); /* 释放被删除结点空间  */
		return FrontElem;
	}
}
bool AddQ(Queue Q, ElementType X) {//尾插
}

#endif // __LINKED_QUENE_H__
