#if !defined(__ARRAY_STACK_H__)
#define __ARRAY_STACK_H__
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
struct Stack {
	int* array;
	unsigned int top;
	unsigned int capcity;
};
typedef struct Stack* Sptr;
Sptr createStack(int n) {
	Sptr stack = (Sptr)malloc(sizeof(struct Stack));
	stack->array = (int*)malloc(sizeof(int) * n);
	stack->top = -1; //index
	stack->capcity = n;
	return stack;
}
int isFill(Sptr stack) {
	return (stack->top == stack->capcity - 1 ? 1 : 0);
}
int isEmpty(Sptr stack) {
	return (stack->top == -1 ? 1 : 0);
}
int push(Sptr stack, int elem) {
	if (isFill(stack))
		return 0;
	stack->array[++(stack->top)] = elem;
	return 1;
}
int pop(Sptr stack) {
	if (isEmpty(stack)) {
		printf("Empty stack!\n");
		return 0;
	}
	return stack->array[(stack->top)--];
}
int top(Sptr stack) {
	if (isEmpty(stack)) {
		printf("Empty stack!\n");
		return 0;
	}
	return stack->array[stack->top];
}
void clear(Sptr stack) {
	free(stack->array);
	free(stack);
}


#endif // __ARRAY_STACK_H__
