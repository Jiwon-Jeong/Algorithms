#include <iostream>
using namespace std;

int gcd(int x, int y) {
	if (y == 0) return x;
	else return gcd(y, x%y);
	return x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t-- > 0) {
		int a[111];
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		long long sum = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				sum += gcd(a[i], a[j]);
			}
		}
		cout << sum << '\n';

	}
	return 0;
}