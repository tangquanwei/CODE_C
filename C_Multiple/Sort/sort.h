#if !defined(__SORT_H__)
#define __SORT_H__
#include <stdio.h>


void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int min(int a, int b) {
	return a < b ? a : b;
}
int less(int a, int b) { return a < b ? 1 : 0; }

void selection_sort(int a[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		int min = i;
		for (int j = i + 1; j < n; ++j) {
			if (a[j] < a[min])
				min = j;
		}
		swap(a + i, a + min);
	}
}
void insertion_sort(int a[], int n) {
	for (int i = 1; i < n; ++i) {
		for (int j = i; j > 0 && less(a[j], a[j - 1]); --j) {
			swap(a + j, a + j - 1);
		}
	}
}
void shell_sort(int a[], int n) {
	int h = 1;
	while (h < n / 3) {
		h = 3 * h + 1;
	}
	while (h >= 1) {
		for (int i = h; i < n; ++i) {
			for (int j = i; j >= h && less(a[j], a[j - h]); j -= h) {
				swap(a + j, a + j - 1);
			}
		}
		h /= 3;
	}
}
/* 归并排序 */
int* aux;
void merge_sort(int a[], int n) { //自顶向下
	aux = (int*)malloc(sizeof(int) * n);
	sort(a, 0, n - 1);
}
void sort(int a[], int lo, int hi) { //分
	if (hi <= lo)
		return;
	int mid = lo + (hi - lo) / 2;
	sort(a, lo, mid);
	sort(a, mid + 1, hi);
	merge(a, lo, mid, hi);
}
void merge(int a[], int lo, int mid, int hi) { //和
	int i = lo, j = mid + 1;
	for (int k = lo; k <= hi; ++k) {
		aux[k] = a[k];
	}
	for (int k = lo; k <= hi; ++k) {
		if (i > mid)				   //左半边用尽
			a[k] = aux[j++];		   //取右半边的元素
		else if (j > hi)			   //右半边用尽
			a[k] = aux[i++];		   //取左半边的元素
		else if (less(aux[j], aux[i])) //右边小于左边
			a[k] = a[j++];			   //取右边
		else						   //右边小于等于左边
			a[k] = aux[i++];		   //取左边
	}
}

void merge_sort_ub(int a[], int n) { //自底向上
	aux = (int*)malloc(sizeof(int) * n);
	for (int sz = 1; sz < n; sz += sz) {
		for (int lo = 0; lo < n - sz; lo += sz + sz) {
			merge(a, lo, lo + sz - 1, min(lo + sz + sz - 1, n - 1));
		}
	}
}
void quick_sort(int s[], int l, int r) {
	if (l < r) {
		//Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换
		int i = l, j = --r, x = s[l];//取区间第一个数为基准数(小)
		while (i < j) {
			while (i < j && s[j] >= x) // 从右向左找第一个小于x的数 ?
				j--;
			if (i < j)//找到了
				s[i++] = s[j];//赋值, 再后移
			while (i < j && s[i] < x) // 从左向右找第一个大于等于x的数
				i++;
			if (i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		quick_sort(s, l, i - 1); // 递归调用
		quick_sort(s, i + 1, r);
	}
}



void show(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	putchar('\n');
}

#endif // __SORT_H__
