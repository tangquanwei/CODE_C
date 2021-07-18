#include <stdio.h>

int main() {
	int i = 1, d = 1;
	double e = 1, ex;

	scanf("%lf", &ex);

	while (d >= ex) {
		d = d * i;
		i++;
		e += 1.0 / d;
	}

	printf("e=%f", e);

	return 0;
}