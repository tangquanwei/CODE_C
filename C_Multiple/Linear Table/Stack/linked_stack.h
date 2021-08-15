#if !defined(__LINKED_STACK_H__)
#define __LINKED_STACK_H__
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node* next;
};
struct Stack {
	struct Node* top;
};
typedef struct Stack* Sptr;
Sptr creatStack(int elem) {
	Sptr s = (Sptr)malloc(sizeof(struct Stack));
	s->top = (struct Node*)malloc(sizeof(struct Node));
	s->top->next = NULL;
	s->top->data = elem;
	return s;
}
int isEmpty(Sptr s) {
	return (s->top == NULL ? 1 : 0);
}
int push(Sptr s, int elem) {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	if (temp == NULL)
		return 0;
	temp->data = elem; // insert head
	temp->next = s->top;
	s->top = temp;
	return 1;
}
int pop(Sptr s) {
	if (isEmpty(s)) {
		printf("Empty stack!\n");
		return 0;
	}
	int data = s->top->data;
	Sptr temp = s->top;
	s->top = s->top->next;
	free(temp);
	return data;
}
int top(Sptr s) {
	if (isEmpty(s)) {
		printf("Empty stack!\n");
		return 0;
	}
	return s->top->data;
}

#endif // __LINKED_STACK_H__
