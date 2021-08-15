#include "linked_queue.h"
// Driver Program to test anove functions
int main() {
	struct Queue* q = createQueue();
	enQueue(q, 10);
	enQueue(q, 20);
	printf("deQueue: %d\n", deQueue(q));
	printf("deQueue: %d\n", deQueue(q));
	enQueue(q, 30);
	enQueue(q, 40);
	enQueue(q, 50);
	deQueue(q);
	printf("Queue Front : %d \n", front(q));
	printf("Queue Rear : %d\n", rear(q));
	return 0;
}