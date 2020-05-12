#include <cstdio>
int c[1001];
int go(int x) {
	if (x == 10000) return 0;
	int a=0, b=0;
	int i, j, k, l;
	i = x % 10; x /= 10;
	j = x % 10; x /= 10;
	k = x % 10; x /= 10;
	l = x % 10;
	if (l == 0) {
		if ((i - j) != (j - k)) return 0;
		else return 1;
	}
	if ((i - j) == (j - k) && (j - k) == (k - l)) return 1;
	else return 0;

}
int main() {
	int n;
	scanf("%d", &n);
	if (n < 100) {
		printf("%d", n);
		return 0;
	}
	int cnt = 99;
	for (int i = 100; i <= n; i++) {
		cnt+=go(i);
	}
	printf("%d", cnt);
}