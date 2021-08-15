/** 
 * 操作 		时间复杂度
 * enqueue()	O(1)
 * dequeue()	O(1)
 */
#if !defined(__LINKED_QUEUE_H__)
#define __LINKED_QUEUE_H__
#define ERROR NULL
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// A linked list (LL) node to store a queue entry
struct QNode {
	int key;
	struct QNode* next;
};

// The queue, front stores the front node of LL and rear stores the
// last node of LL
struct Queue {
	struct QNode *front, *rear;
};

// A utility function to create a new linked list node.
struct QNode* newNode(int k) {
	struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
	temp->key = k;
	temp->next = NULL;
	return temp;
}

// A utility function to create an empty queue
struct Queue* createQueue() {
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q->front = q->rear = NULL;
	return q;
}

// The function to add a key k to q
void enQueue(struct Queue* q, int k) {
	// Create a new LL node
	struct QNode* temp = newNode(k);

	// If queue is empty, then new node is front and rear both
	if (q->rear == NULL) {
		q->front = q->rear = temp;
		return;
	}

	// Add the new node at the end of queue and change rear
	q->rear->next = temp;
	q->rear = temp; //rearward shift(后移)
}

// Function to remove a key from given queue q
int deQueue(struct Queue* q) {
	// If queue is empty, return NULL.
	if (q->front == NULL)
		return;

	// Store previous front and move front one node ahead
	struct QNode* temp = q->front;
	int key = temp->key;
	q->front = q->front->next;


	// If front becomes NULL, then change rear also as NULL
	if (q->front == NULL)
		q->rear = NULL;

	free(temp);
	return key;
}
int front(struct Queue* q) {
	return q->front->key;
}
int rear(struct Queue* q) {
	return q->rear->key;
}



#endif // __LINKED_QUEUE_H__
