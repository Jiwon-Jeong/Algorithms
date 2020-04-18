#include <iostream>
#include <algorithm>
using namespace std;
int a[1001][3];
int d[1001][3];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	for (int i = 1; i <= t; i++) {
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + a[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + a[i][1];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + a[i][2];
	}
	cout << min({ d[t][0], d[t][1], d[t][2] }) << "\n";
}