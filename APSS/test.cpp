#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int d[12], t;
	d[1] = 1, d[2] = 2, d[3] = 4;
	for (int i = 4; i <= 11; i++) {
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
	}

	cin >> t;
	while (t-- ) {
		int n;
		cin >> n;
		cout << d[n] << "\n";
	}
}