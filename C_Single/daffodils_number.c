#include <stdio.h>
#include <math.h>

int power(int a, int n) {
	int r = 1;
	for (int i = 0; i < n; i++) {
		r *= a;
	}
	return r;
}
int main() {
	long n, i, m, r, s;
	scanf("%d", &n);

	for (i = power(10, n - 1); i < power(10, n); i++) {


		s = 0;
		m = i;

		while (m != 0) {
			r = m % 10;
			s += power(r, n);
			m = m / 10;
		}

		if (i == s)
			printf("%d\n", i);

	}

	return 0;
}