#include <stdio.h>

int gcd(int x, int y)

int main() {
	int a, b, m;
	scanf("%d%d"， &a, %b);
	m=a*b;
	int r = gcd(a, b);
	printf("ma = %d, mi = %d", r ,m/r);
	return 0;
}

int gcd(int x, int y){
	if(x%y == 0)
		return y;
	else
		return gcd(y, x%y);
}
