#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) {
		v[i] = i + 1;
	}
	do {
		for (int i = 0; i < n; i++) {
			cout << v[i];
			if (i != n - 1) cout << ' ';
		}
		cout << "\n";
	} while (next_permutation(v.begin(), v.end()));
	return 0;
}