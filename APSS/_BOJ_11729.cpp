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
	int k = 1;
	for (int i = 0; i < n; i++)
		k *= 2;
	printf("%d\n", k - 1);
	if (n <= 20)
		hanoi(n, 1, 2, 3);
	return 0;
}