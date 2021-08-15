/** 
 * 队列是一种线性结构，它遵循执行操作的特定顺序。顺序是先进先出 (FIFO)。
 * 
 * 数组实现的优点：  
 * 1) 易于实施。
 * 
 * 数组实现的缺点：  
 * 1) 静态数据结构，固定大小。
 * 2)如果队列有大量的入队和出队操作，在某些时候（在前后索引线性递增的情况下），即使队列为空，我们也可能无法在队列中插入元素（避免了这个问题）通过使用循环队列）。
 * 
 * Queue 的这个属性使其在以下场景中也很有用
 * 1) 当一个资源在多个消费者之间共享时。示例包括 CPU 调度、磁盘调度。 
 * 2) 当数据在两个进程之间异步传输时（数据的接收速率不一定与发送速率相同）。实例包括IO缓冲器，管道，文件IO等
 * 
 * 操作              	复杂度
 * Enque(insertion) 	O(1) 
 * Deque(deletion) 		O(1) 
 * Front(Get front) 	O(1) 
 * Rear(Get Rear) 		O(1)   
 * 
 * 辅助空间： O(N)  N 是用于存储元素的数组的大小
 */
#if !defined(__ARRAY_QUENE_H__)
#define __ARRAY_QUENE_H__
// C program for array implementation of queue
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a queue
struct Queue {
	int front, rear, size;
	unsigned capacity;
	int* array;
};
typedef struct Queue* Qptr;

// function to create a queue of given capacity.
// It initializes size of queue as 0
struct Queue* createQueue(unsigned capacity) {
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;

	// This is important, see the enqueue
	queue->rear = capacity - 1; // point to the  index of the last element
	queue->array = (int*)malloc(queue->capacity * sizeof(int));
	return queue;
}

// Queue is full when size becomes equal to the capacity
int isFull(struct Queue* queue) {
	return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
int isEmpty(struct Queue* queue) {
	return (queue->size == 0);
}

// Function to add an item to the queue.
// It changes rear and size
void enqueue(struct Queue* queue, int item) {
	if (isFull(queue)) {
		printf("The Queue is fill!\n");
		return;
	}
	// 如果后面用完了就用前面的空间
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;
	queue->size++;
	printf("%d enqueued to queue\n", item);
}

// Function to remove an item from queue.
// It changes front and size
int dequeue(struct Queue* queue) {
	if (isEmpty(queue))
		return INT_MIN;
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size = queue->size - 1;
	return item;
}

// Function to get front of queue
int front(struct Queue* queue) {
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->front];
}

// Function to get rear of queue
int rear(struct Queue* queue) {
	if (isEmpty(queue))
		return INT_MIN;
	return queue->array[queue->rear];
}
#endif // __ARRAY_QUEUE_H__
