#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<vector<int>>w(n, vector<int>(n, 0));
	vector<int> v(n, 0);
	for (int i = 0; i< n; i++) {
		v[i] = i;
		for (int j = 0; j < n; j++) {
			cin>>w[i][j];
		}
	}
	int min = 1e9;
	do {
		int sum = 0; bool flag = true;
		for (int i = 0; i < n - 1; i++) {
			if (w[v[i]][v[i + 1]] == 0) {
				flag = false;
				break;
			}
			else
				sum += w[v[i]][v[i + 1]];
		}
		if (flag && w[v[n - 1]][v[0]] != 0) {
			sum += w[v[n - 1]][v[0]];
			min = min > sum ? sum : min;
		}
	} while (next_permutation(v.begin(), v.end()));

	cout << min << "\n";
	return 0;
}