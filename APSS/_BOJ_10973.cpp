#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	if (prev_permutation(v.begin(), v.end())) {
		for (int i = 0; i < n; i++) {
			cout << v[i];
			if (i != n - 1)
				cout << " ";
		}
		cout << "\n";
	}
	else
		cout << -1 << "\n";
	return 0;
}