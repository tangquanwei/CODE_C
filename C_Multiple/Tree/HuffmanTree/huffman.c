#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct Node* HuffmanTree;
struct Node {
	int weight;
	HuffmanTree left, right;
};
HuffmanTree Huffman(MinHeap H) {
	int i;
	HuffmanTree T;
	BuildMinHeap(H);
	for (i = 1; i < H->Size; ++i) {
		T = malloc(sizeof(struct Node));
		T->left = DeleteMin(H);
		T->right = DeleteMin(H);
		T->weight = T->left->weight + T->right->weight;
		Insert(H, T);
	}
	T = DeleteMin(H);
	return T;
}