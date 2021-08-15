#include "sort.h"
#include <stdlib.h> //qsort
#include <time.h>

int main(int argc, char const* argv[]) {
	const int SIZE = 1000000;
	const int n = 100;
	int m;
	int b[n];
	srand((unsigned)1);
	for (int i = 0; i < n; ++i) {
		b[n] = rand;
	}

	if (1) {
		clock_t t6 = clock();
		m = SIZE;
		while (m--) {
			int a[n];
			for (int i = 0; i < n; ++i) {
				a[n] = rand;
			}
			qsort(a, 10, sizeof(*a), less);
		}
		printf("CUP time used: %d\tqsort\n", clock() - t6);

		clock_t t1 = clock();
		m = SIZE;
		while (m--) {
			int a[n];
			for (int i = 0; i < n; ++i) {
				a[n] = rand;
			}
			shell_sort(a, n);
		}
		printf("CUP time used: %d\tshell_sort\n", clock() - t1);
		clock_t t2 = clock();
		m = SIZE;
		while (m--) {
			int a[n];
			for (int i = 0; i < n; ++i) {
				a[n] = rand;
			}
			insertion_sort(a, n);
		}
		printf("CUP time used: %d\tinsertion_sort\n", clock() - t2);
		clock_t t3 = clock();
		m = SIZE;
		while (m--) {
			int a[n];
			for (int i = 0; i < n; ++i) {
				a[n] = rand;
			}
			selection_sort(a, n);
		}
		printf("CUP time used: %d\tselection_sort\n", clock() - t3);
		clock_t t4 = clock();
		m = SIZE;
		while (m--) {
			int a[n];
			for (int i = 0; i < n; ++i) {
				a[n] = rand;
			}
			merge_sort(a, n);
		}
		printf("CUP time used: %d\tmerge_sort\n", clock() - t4);
		clock_t t5 = clock();
		m = SIZE;
		while (m--) {
			int a[n];
			for (int i = 0; i < n; ++i) {
				a[n] = rand;
			}
			quick_sort(a, 0, n);
			if(m==1)
			show(a,n);
		}
		printf("CUP time used: %d\tquick_sort\n", clock() - t5);
	}



	return 0;
}
