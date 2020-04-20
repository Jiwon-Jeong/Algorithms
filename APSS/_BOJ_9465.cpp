#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<vector<int>>s(2, vector<int>(n + 1, 0));
		vector<vector<int>>d(2, vector<int>(n + 1, 0));
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> s[i][j];
			}
		}

		for (int j = 0; j < n; j++) {
			if (j == 0) {
				d[0][j] = s[0][j];
				d[1][j] = s[1][j];
			}
			if (j -1 == 0) {
				d[0][j] = s[0][j] + d[1][j - 1];
				d[1][j] = s[1][j] + d[0][j - 1];
			}
			if (j - 2 >= 0) {
				d[0][j] = s[0][j] + max(d[1][j - 1], d[1][j-2]);
				d[1][j] = s[1][j] + max(d[0][j - 1], d[0][j-2]);
			}
		}
		cout << max(d[0][n-1], d[1][n-1]) << "\n";
	}
}