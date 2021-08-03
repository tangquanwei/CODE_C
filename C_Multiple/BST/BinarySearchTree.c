#include "binary_search_tree.h"
#include <stdio.h>
#include <stdlib.h>
/* 从二叉搜索树中查找元素x，并返回节点地址 */
Position BST_find(BST tree, ElementType x) {
	if (!tree) // 第一步判断是否为空
		return NULL;
	if (x > tree->data)
		return BST_find(tree->right, x);
	else if (x < tree->data)
		return BST_find(tree->left, x);
	else
		return tree;
}
Position BST_findLoop(BST tree, ElementType x) {
	while (tree) {
		if (x > tree->data)
			tree = tree->right;
		else if (x < tree->data)
			tree = tree->left;
		else
			return tree;
	}
	return NULL;
}
/* 返回二叉搜索树中最小元素所在节点的地址 */
Position BST_min(BST tree) {
	if (!tree)
		return NULL;
	else if (tree->left == NULL)
		return tree;
	else
		return BST_min(tree->left);
}
Position BST_minLoop(BST tree) {
	if (tree)
		while (tree->left)
			tree = tree->left;
	return tree;
}
/* 返回二叉搜索树中最大元素所在节点的地址 */
Position BST_max(BST tree) {
	if (!tree)
		return NULL;
	else if (!tree->right)
		return tree;
	else
		return BST_max(tree->right);
}
Position BST_maxLoop(BST tree) {
	if (tree)
		while (tree->right)
			tree = tree->right;
	return tree;
}
/* 向二叉搜索树中插入元素x */
BST BST_insret(BST* ptr_to_tree, ElementType x) {
	BST tree = *ptr_to_tree; //
	if (!tree) {
		tree = (BST)malloc(sizeof(struct Node));
		tree->data = x;
		tree->left = tree->right = NULL;
	}
	else {
		if (x < tree->data)
			tree->left = BST_insret(&tree->left, x);
		else if (x > tree->data)
			tree->right = BST_insret(&tree->right, x);
		/* x == tree->data do nothing */
	}
	return (*ptr_to_tree = tree); // return back
}
/* 删除二叉搜索树中的元素x */
/** 
 * Q:要删除的节点只有一个子节点
 * A:将其父节点的指针指向要删除的节点的子节点
 * Q:要删除的节点有左右两颗子树
 * A:用右子树元素最小值或左子树元素最大值代替
 */
BST BST_delete(BST* ptr_to_tree, ElementType x) {
	BST tree = *ptr_to_tree;
	Position temp;
	if (!tree)
		printf("NOT FOUND!");
	else if (x < tree->data)
		tree->left = BST_delete(&tree->left, x);
	else if (x > tree->data)
		tree->right = BST_delete(&tree->right, x);
	else {// 找到了
		if (tree->left && tree->right) {	 // 被删除的节点有左右子节点
			temp = BST_minLoop(tree->right); // 在右子树中找最小的元素填充，删除节点
			tree->data = temp->data;
			tree->right = BST_delete(&tree->right, tree->data); //删掉填充节点
		}
		else { //被删除节点有一个或无子节点
			temp = tree;
			if (!tree->left) //只有右子节点或无子节点
				tree = tree->right;
			else if (!tree->right)
				tree = tree->left;
			free(temp);
		}
	}
	return (*ptr_to_tree = tree);
}

int main() {
	BST tree1 = NULL; //NULL

	BST_insret(&tree1, 100);
	BST_insret(&tree1, 200);
	BST_insret(&tree1, 50);
	BST_delete(&tree1, 50);
	return 0;
}
