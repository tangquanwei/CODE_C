#include "array_queue.h"
// Driver program to test above functions./
int main() {
	Qptr queue = createQueue(3);

	enqueue(queue, 10);
	enqueue(queue, 20);
	enqueue(queue, 30);
	enqueue(queue, 40);
	printf("Front item is %d\n", front(queue));

	printf("%d dequeued from queue\n\n",dequeue(queue));
	enqueue(queue, 40);

	printf("Front item is %d\n", front(queue));
	printf("Rear item is %d\n", rear(queue));

	return 0;
}
