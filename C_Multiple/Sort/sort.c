#include "sort.h"
#include "time.h"

int main(int argc, char const* argv[]) {
	// clock_t t1 = clock();
	// int m = 100000000;
	// while (m--) {
	// 	int a[] = { 2, 1, 3, 4, 8, 7, 5, 6, 11, 10 };
	// 	shell_sort(a, n);
	// }
	// printf("CUP time used: %d\n", clock() - t1);
	// clock_t t2 = clock();
	// m = 100000000;
	// while (m--) {
	// 	int a[] = { 2, 1, 3, 4, 8, 7, 5, 6, 11, 10 };
	// 	insertion_sort(a, n);
	// }
	// printf("CUP time used: %d\n", clock() - t2);
	// clock_t t3 = clock();
	// m = 100000000;
	// while (m--) {
	// 	int a[] = { 2, 1, 3, 4, 8, 7, 5, 6, 11, 10 };
	// 	selection_sort(a, n);
	// }
	// printf("CUP time used: %d\n", clock() - t2);

	int c[] = { 2, 1, 4, 3, 9, 7, 5, 1438291, 8, 0 };
	merge_sort_ub(c, 10);
	show(c, 10);
	return 0;
}
