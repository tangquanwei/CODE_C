#include <stdio.h>

int fact(int n) {
	int f;

	for (f = 1; f <= n; f++) {

		f *= n;
	}

	return f;
}

int main() {
	int i = 1, d = 1, x;
	double item = 1, sum = 1, e;

	scanf("%lf", &e);

	while (item > e) {
		item = 1.0 / d;
		i++;
		d = d * i;

		sum += item;
	}

	printf("%lf", sum);
	return 0;
}
