#if !defined(__QUICK_SORT_H__)
#define __QUICK_SORT_H__
/**
 * 快速排序
 * 1．先从数列中取出一个数作为基准数。
 * 2．分区过程，将比这个数大的数全放到它的右边，小于或等于它的数全放到它的左边。
 * 3．再对左右区间重复第二步，直到各区间只有一个数。  
 */
void quick_sort(int a[], int n) {
	sort(a, 0, n - 1);
}
void sort(int a[], int lo, int hi) {
	if (hi < lo)
		return;
	int j = partition(a, lo, hi);
	sort(a, lo, j - 1);
	sort(a, j + 1, hi);
}
int partition(int a[], int lo, int hi) {
	int i = lo, j = hi + 1;
	int v = a[lo];
	while (i < j) {
		while (less(a[++i], v))
			if (i == hi)
				break;
		while (less(v, a[--j]))
			if (j == lo)
				break;
	}
	swap(a, lo, j);
	return j;
}
int less(int a, int b) {
	return a < b ? 1 : 0;
}
void swap(int a[], int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
void quick3way(int a[], int lo, int hi) {
	if (hi <= lo)
		return;
	int lt = lo, i = lo + 1, gt = hi;
	int v = a[lo];
	while (i <= gt) {
		int ret = cmp(a[i], v);
		if (cmp < 0)
			swap(a, lt++, i++);
		else if (cmp > 0)
			swap(a, i, gt--); 
		else
			++i;
	}
	sort(a, lo, lt - 1);
	sort(a, gt + 1, hi);
}
int cmp(int a, int b) {
	return a - b;
}


#endif // __QUICK_SORT_H__
