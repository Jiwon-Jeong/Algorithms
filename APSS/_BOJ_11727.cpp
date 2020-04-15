#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int d[1001];
	for (int i = 1; i <= n; i++) {
		d[1] = 1;
		d[2] = 3;
		if (i >= 3) {
			d[i] = (d[i - 1] + 2 * d[i - 2])%10007;
		}
	}
	cout << d[n] << "\n";
}