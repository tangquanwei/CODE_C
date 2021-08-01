#if !defined(__SORT_H__)
#define __SORT_H__
const int n = 10;


void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
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
		for (int j = i; j > 0 && less(a[j],a[j-1]); ++j) {
			swap(a + j, a + j - 1);
		}
	}
}
void show(int a[]) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf('\n');
}

#endif // __SORT_H__
