#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int cache[101];
const int MOD = 1000000007;

int tiling(int x) {

	if (x <= 1) return 1;

	int& ret = cache[x];
	if (ret != -1) return ret;

	return (tiling(x - 2) + tiling(x - 1));
}


int asymTiling(int x) {
	// x가 홀수
	if (x % 2 == 1) {
		return (tiling(x) - tiling(x / 2) + MOD) % MOD;
	}
	int ret = tiling(x);
	// x가 짝수 - 두 가지 경우
	ret = (ret - tiling(x / 2) + MOD) % MOD;
	ret = (ret - tiling(x / 2 - 1) + MOD) % MOD;
	return ret;
}

int main(void) {
	memset(cache, -1, sizeof(cache));
	int c,n;
	cin >> c;

	while (c-- > 0) {
		cin >> n;
		cout << asymTiling(n) << endl;
	}

	return 0;
}