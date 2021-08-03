#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node* PtrToNode;
struct Node {
	ElementType data;
	PtrToNode next;
};
typedef PtrToNode List;
typedef PtrToNode Position;

List readHead() {
	int n;
	printf("n = ");
	scanf("%d", &n);
	List list = (List)malloc(sizeof(struct Node));
	list->next = NULL;
	List p;
	while (n--) {
		p = (List)malloc(sizeof(struct Node));
		// scanf("%d", &(p->data));
		p->data = n;
		p->next = list->next; // 1
		list->next = p;		  // 2
	}
	p = list;
	list = list->next;
	free(p);
	return list;
}
List readTail() {
	List list, p, r;
	list = (List)malloc(sizeof(struct Node));
	list->next = NULL;
	r = list;
	int n;
	printf("n = ");
	scanf("%d", &n);
	while (n--) {
		p = (List)malloc(sizeof(struct Node));
		p->data = n;
		p->next = r->next; //1
		r->next = p;	   //2
		r = p;			   //3
	}
	p = list;
	list = list->next;
	free(p);
	return list;
}
List toList(ElementType a[], int length) {
	List list = (List)malloc(sizeof(struct Node));
	list->next = NULL;
	List p;
	while (length--) {
		p = (List)malloc(sizeof(struct Node));
		p->data = a[length];
		p->next = list->next;
		list->next = p;
	}
	p = list;
	list = list->next;
	free(p);
	return list;
}
void print(List list) {
	while (list) {
		if (list->next)
			printf("%d -- ", list->data);
		else
			printf("%d", list->data);
		list = list->next;
	}
	putchar('\n');
}


List reverse(List l) {
	List p = l, q;
	l = NULL;
	while (p) {
		q = p;
		p = p->next;
		q->next = l;
		l = q;
	}
	return l;
}

int main() {
	// List l1 = readHead();
	// print(l1);
	// print(reverse(l1));
	// List l2 = readTail();
	// print(l2);
	int a[] = { 2, 3, 4, 5, 6, 1, 2, 3, 4, 5 };
	List l3 = toList(a, 10);
	print(l3);
	return 0;
}
