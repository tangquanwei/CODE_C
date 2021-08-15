/*****************************************************************************************
 * 
 * 分治法(Divide-and-ConquerMethod)
 * 
 * 挖坑填数+分治法：
 * 
 * 1．先从数列中取出一个数作为基准数。
 * 
 * 2．分区过程，将比这个数大的数全放到它的右边，小于或等于它的数全放到它的左边。
 * 
 * 3．再对左右区间重复第二步，直到各区间只有一个数。  
 * 
 ****************************************************************************************/
#include <stdio.h>

void show(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	putchar('\n');
}
void quick_sort(int s[], int l, int r) {
	if (l < r) {
		//Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换
		int i = l, j = r, x = s[l];//取区间第一个数为基准数(小)
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
void quick_sort1(int s[], int l, int r) {
	if (l < r) {
		int i = l, j = r, x = s[r];//取区间最后数为基准数(大)
		while (i < j) {
			while (i < j && s[i] < x) // 从左向右找第一个大于等于x的数
				i++;
			if (i < j)
				s[j--] = s[i];
			while (i < j && s[j] >= x) // 从右向左找第一个小于x的数 ?
				j--;
			if (i < j)//找到了
				s[i++] = s[j];
		}
		s[j] = x;
		quick_sort1(s, l, i - 1); // 递归调用
		quick_sort1(s, i + 1, r);
	}
}
int main(int argc, char const* argv[]) {
	int a[] = { 3, 2, 1, 4, 35, 13, 4124, 41, 4643562, 12 };
	quick_sort1(a, 0, 10);
	show(a, 10);
	return 0;
}
