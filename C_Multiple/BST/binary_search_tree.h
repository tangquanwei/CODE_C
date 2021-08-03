#if !defined(__BINARY_SEARCH_TREE__)
#define __BINARY_SEARCH_TREE__

/**
 * 非空左子树所以键值小于根节点键值
 * 非空右子树所以键值大于根节点键值
 * 左右子树都是二叉搜索树
 */

typedef int ElementType;
typedef struct Node* BST;
struct Node {
	ElementType data;
	BST left;
	BST right;
};
typedef BST Position;

/* 从二叉搜索树中查找元素x，并返回节点地址 */
Position BST_find(BST tree, ElementType x);
Position BST_findLoop(BST tree, ElementType x);

/* 返回二叉搜索树中最小元素所在节点的地址 */
Position BST_min(BST tree);
Position BST_minLoop(BST tree);

/* 返回二叉搜索树中最大元素所在节点的地址 */
Position BST_max(BST tree);
Position BST_maxLoop(BST tree);

/* 向二叉搜索树中插入元素x */
BST BST_insret(BST* ptr_to_tree, ElementType x);
/* 删除二叉搜索树中的元素x */
BST BST_delete(BST* ptr_to_tree, ElementType x);


#endif // __BINARY_SEARCH_TREE__
