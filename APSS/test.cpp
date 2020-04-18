#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> d(n + 1);
	vector<int> p(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		d[i] = p[i];
	}
	d[0] = 0;
	if (n >= 2) {
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				if (n - i + j)
					d[i] = max(d[i], p[i - j] + d[j]);
			}
		}
	}
	cout << d[n] << "\n";
}