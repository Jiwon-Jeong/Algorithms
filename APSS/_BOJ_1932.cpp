#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<vector<int>>a(n + 1, vector<int>(n + 1, 0));
	vector<vector<int>>d(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++)
			cin >> a[i][j];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + a[i][j];
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, d[n][i]);
	}
	cout << ans << "\n";
}