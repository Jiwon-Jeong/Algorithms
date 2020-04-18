#include <stdio.h>
long long mod = 1000000009LL;
long long d[1000001];

int main() {
	int t;
	d[1] = 1, d[2] = 2, d[3] = 4;
	for (int i = 4; i <= 1000000; i++) {
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
		d[i] %= mod;
	}
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", d[n]);
	}
}