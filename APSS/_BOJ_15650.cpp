#include <iostream>
using namespace std;
bool c[10];
int a[10];
void go(int index, int start, int n, int m) {
	if (m == index) {
		for (int j = 0; j < m; j++) {
			cout << a[j];
			if (j != m - 1) cout << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = start; i <=n; i++) {
		if (c[i]) continue;
		c[i] = true;
		a[index] = i;
		go(index + 1, i+1, n, m);
		c[i] = false;
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	go(0, 1, n, m);
	return 0;
}