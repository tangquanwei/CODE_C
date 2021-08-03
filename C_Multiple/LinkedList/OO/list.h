#if !defined(__LIST_H__)
#define __LIST_H__

typedef int ElementType;
typedef struct Node* PtrToNode;
struct Node {
	ElementType data;
	PtrToNode next;
};
typedef PtrToNode List;
typedef PtrToNode Position;
/* you get 0-n */
void List_ctor(List* self, int n);
/* get list form an array */
void List_ctor_array(List* self, ElementType a[], int length);
/* reverse */
void List_reverse(List* self);
/* sort */
void List_sort(List* self);
/* print list */
void List_print(List self);
/* input element return index_pointer */
Position List_find(List self, ElementType element);
/* input index return element */
ElementType List_getIndexOf(List self, int index)



#endif // __LIST_H__
