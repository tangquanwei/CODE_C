#if !defined(__BIN_TREE_H__)
#define __BIN_TREE_H__
#include <stdio.h>
/* 二叉树 */
typedef struct TreeNode* BinTree;
typedef BinTree Position;
typedef int ElementType;
/* 二叉树的结点 */
struct TreeNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};
/**
 * 先序遍历 
 * 1.访问根节点
 * 2.先序遍历左子树
 * 3.先序遍历右子树
 */
void preOrderTraversal(BinTree BT) {
	if (BT) {
		printf("%d ", BT->Data);
		preOrderTraversal(BT->Left);
		preOrderTraversal(BT->Right);
	}
}
/**
 * 中序遍历
 * 1.中序遍历左子树
 * 2.访问根节点
 * 3.中序遍历右子树
 */
void InOrderTraversal(BinTree BT) {
	if (BT) {
		preOrderTraversal(BT->Left);
		printf("%d ", BT->Data);
		preOrderTraversal(BT->Right);
	}
}
void InOrderTraversalLoop(BinTree BT){
    BinTree T=BT;
;
}
/**  
 * 后序遍历
 * 1.后续遍历左子树
 * 2.后续遍历右子树
 * 3.访问根节点
 */
void PostOrderTraversal(BinTree BT) {
	if (BT) {
		preOrderTraversal(BT->Left);
		preOrderTraversal(BT->Right);
		printf("%d ", BT->Data);
	}
}
/** 
 * 层序遍历
 * 
 */



#endif // __BIN_TREE_H__
