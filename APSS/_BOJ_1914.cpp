#include <math.h>
#include <iostream>
using namespace std;

void hanoi(int n, int from, int pass, int to) {
	if (n == 1) {
		printf("%d %d\n", from, to);
		return;
	}
	hanoi(n - 1, from, to, pass);
	printf("%d %d\n", from, to);
	hanoi(n - 1, pass, from, to);
}

int main() {
	int n;
	scanf("%d", &n);
	long long a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		b *= 2;
		a = a * 2 + 1;
		b += a / 1000000000000000000;
		a %= 1000000000000000000;
	}
	if (b != 0)
		printf("%lld", b);
	printf("%lld\n", a);
	if (n <= 20)
		hanoi(n, 1, 2, 3);
	return 0;
}