#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		x--;
		y--;
		bool flag = false;
		for (int i = x; i < m*n; i+=m) {
			if (i%n == y) {
				cout << i + 1 << "\n";
				flag = true;
				break;
			}
		}
		if (flag == false)
			cout << -1 << "\n";
	}
	return 0;
}