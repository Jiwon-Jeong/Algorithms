#include <stdio.h>
using namespace std;
const long long mod = 1000000000LL;
int main() {
	int n;
	long long d[101][10], result=0;
	scanf("%d", &n);
	d[1][0] = 0;
	for (int i = 1; i <= 9; i++)
		d[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			d[i][j] = 0;
			if (j + 1 <= 9)
				d[i][j] += d[i - 1][j + 1];

			if (j - 1>= 0)
				d[i][j] += d[i - 1][j - 1];

			d[i][j] %= mod;
		}
	}

	for (int i = 0; i <= 9; i++) {
		result += d[n][i];
	}
	printf("%lld\n", result%mod);
}