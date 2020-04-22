#include <iostream>
using namespace std;
int main() {
	long long n;
	cin >> n;
	int len = 1;
	long long ans = 0;
	for (int i = 1; i <= n; i*=10, len++) {
		int end = i * 10 - 1;
		if (n <end) {
			end = n;
		}
		ans += (long long)(end - i + 1) * len;
	}
	cout << ans << "\n";
	return 0;
}