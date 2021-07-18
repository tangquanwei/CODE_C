#include <stdio.h>
int power(int a, int n);
int main() {
	int n, i, r, num;
	scanf("%d", &n);
	for (i = power(10, n - 1); i < power(10, n); i++) {
		num = i;
		r = 0;
		while (num) {
			r += power(num % 10, n);
			num /= 10;
		}
		if (r == i) {
			printf("%d\n", r);
		}
	}
	return 0;
}

int power(int a, int n) {//ÇóÃÝ
	int i;
	int r = 1;

	for (i = 0; i < n; i++) {

		r *= a;
	}

	return r;
}