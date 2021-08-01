#if !defined(__ARRAY_QUENE_H__)
#define __ARRAY_QUENE_H__
#define ERROR NULL;
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef int Position;
struct QNode
{
    ElementType *Data; /* 存储元素的数组 */
    Position Front;    /* 队列的头指针, 元素下标 */
    Position Rear;     /* 队列的尾指针 */
    int MaxSize;       /* 队列最大容量 */
};
typedef struct QNode *Queue;

Queue CreateQueue(int MaxSize);

bool IsFull(Queue Q);

bool AddQ(Queue Q, ElementType X);

bool IsEmpty(Queue Q);

ElementType DeleteQ(Queue Q);

#endif // __ARRAY_QUENE_H__
