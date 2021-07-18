#include <stdio.h>

int main() {
	int n, i, j, it = 1;
	int sum = 0;
	scanf("%d", &n);

	for (i = 1; 1 <= n; i++) {

		for (j = 1; j <= i; j++) {

			it *= j;
			sum += it;
		}
	}

	printf("%d", sum);
	return 0;
}