#include <stdio.h>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	long long d[91][2];
	d[1][1] = 1;
	d[1][0] = 0;
	for (int i = 2; i <= n; i++) {
		d[i][0] = d[i][1] = 0;
		d[i][0] += d[i - 1][0] + d[i - 1][1];
		d[i][1] += d[i - 1][0];
	}
	printf("%lld\n", d[n][0] + d[n][1]);
}