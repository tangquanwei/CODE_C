#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void List_ctor(List* self, int n) {
	List list, p, r;
	list = (List)malloc(sizeof(struct Node));
	list->next = NULL;
	r = list;
	while (n--) {
		p = (List)malloc(sizeof(struct Node));
		p->data = n;
		p->next = r->next;
		r->next = p;
		r = p;
	}
	*self = list->next;
	free(list);
}
void List_ctor_array(List* self, ElementType a[], int length) {
	List list = (List)malloc(sizeof(struct Node));
	list->next = NULL;
	List p;
	while (length--) {
		p = (List)malloc(sizeof(struct Node));
		p->data = a[length];
		p->next = list->next;
		list->next = p;
	}
	*self = list->next;
	free(list);
}
int List_length(List self) {
	int i = 0;
	for (; self; self = self->next, ++i)
		;
	return i;
}
void List_toArray(List self, ElementType a[]) {
	for (int i = 0; self; self = self->next, ++i) {
		a[i] = self->data;
	}
}
void swap(ElementType* a, ElementType* b) {
	ElementType temp = *a;
	*a = *b;
	*b = temp;
}
int less(ElementType a, ElementType b) { return a < b ? 1 : 0; }
int more(ElementType a, ElementType b) { return a > b ? 1 : 0; }
// 回调函数就是一个通过函数指针调用的函数
void shell_sort(int a[], int n, int (*cmp)(ElementType, ElementType)) {
	int h = 1;
	while (h < n / 3) {
		h = 3 * h + 1;
	}
	while (h >= 1) {
		for (int i = h; i < n; ++i) {
			for (int j = i; j >= h && cmp(a[j], a[j - h]); j -= h) {
				swap(a + j, a + j - 1);
			}
		}
		h /= 3;
	}
}
void List_sort(List* self) {
	/* 转化为数组排序，再转回去 */
	List list = *self;
	int n = List_length(list);
	ElementType a[n];
	List_toArray(list, a);
	shell_sort(a, n, less);
	List_ctor_array(self, a, n);
}
void List_reverse(List* self) {
	List p = *self, q;
	*self = NULL;
	while (p) {
		q = p;
		p = p->next;
		q->next = *self;
		*self = q;
	}
}
void List_print(List self) {
	while (self) {
		if (self->next)
			printf("%d -- ", self->data);
		else
			printf("%d", self->data);
		self = self->next;
	}
	putchar('\n');
}


int main(int argc, char const* argv[]) {
	List l1, l2;
	int a[] = { 1, 3, 2, 5, 4, 6, 8, 7, 9, 0 };
	List_ctor_array(&l2, a, 10);
	List_print(l2);
	List list = l2;
	List_sort(&l2);
	List_print(l2);
	return 0;
}