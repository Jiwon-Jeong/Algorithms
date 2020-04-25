#include <iostream>
using namespace std;
int main() {
	int n, s;
	int a[20];
	cin >> n>> s;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int ans = 0;

	for (int i = 1; i < (1 << n); i++) {
		int tmp = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j))
				tmp += a[j];
		}
		if (tmp == s)
			ans++;
	}
	cout << ans << "\n";

}