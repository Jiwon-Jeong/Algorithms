#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[10]; bool c[10];
void go(vector<int>&num, int index, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i];
			if (i != m - 1)
				cout << ' ';
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		if (c[i]) continue;
		c[i] = true;
		a[index] = num[i];
		go(num, index + 1, n, m);
		c[i] = false;
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> num(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num.begin(), num.end());
	go(num, 0, n, m);
}