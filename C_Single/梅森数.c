#include <stdio.h>

int narcissistic( int number );
void PrintN( int m, int n );

int main() {
	int m, n;

	scanf("%d %d", &m, &n);

	if ( narcissistic(m) )
		printf("%d is a narcissistic number\n", m);
	PrintN(m, n);

	if ( narcissistic(n) )
		printf("%d is a narcissistic number\n", n);

	return 0;
}

int narcissistic( int number ) {
	int m, n, i, r = 1, s = 0;
	m = n = number;

	for (i = 0; n > 0; i++)

		n /= 10;

	while (m) {
		while (i) {
			r *= m % 10;
			i--;
		}

		s += r;
		m /= 10;
	}

	if (number == s)
		return 1;
	else
		return 0;
}

void PrintN( int m, int n ) {
	for (; m <= n; m++) {

		if (narcissistic(m) == 1)
			printf("%d\n", m);
	}
}