#include "linked_stack.h"
int main() {
	Sptr s = creatStack(5);
    push(s,10);
    printf("pop: %d\n",pop(s));
    printf("top: %d\n",top(s));
    printf("pop: %d\n",pop(s));
    printf("pop: %d\n",pop(s));
    printf("pop: %d\n",pop(s));
	return 0;
}
