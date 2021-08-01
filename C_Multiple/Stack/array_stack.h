#ifndef __STACK_H__
#define __STACK_H__
#define MaxSize 100
#include <stdio.h>
typedef struct
{
	int Data[MaxSize]; // 存储元素的数组
	int topIdx;		   //栈顶指针
} SeqStack;
//return 0 为false,1为true(下同)
// 将元素推入栈中
int Push(SeqStack& L, int e) { // 栈已满
	if (L.topIdx == MaxSize - 1) {
		return 0;
	}
	// 加入栈中
	L.Data[L.topIdx++] = e;
	// 返回自身
	return e;
}
// 移除栈顶元素
int Pop(SeqStack& L) { // 栈空
	if (L.topIdx == 0) {
		//返回失败
		return 0;
	}
	// 打印并返回栈
	int val = L.Data[--L.topIdx];
	printf("%d ", val);
	return val;
}
//判断栈s是否为空
int isEmpty(SeqStack s) {
	// 如果下标在0，说明栈中无元素
	if (s.topIdx != 0) {
		return 1;
	}
	return 0;
}
// 判断栈是否已栈.
int isFull(SeqStack s) {
	// 已满返回true(1)
	if (s.topIdx != MaxSize - 1) //之前的定义数组的最大值的下标
	{
		return 1;
	}
	return 0;
}
#endif