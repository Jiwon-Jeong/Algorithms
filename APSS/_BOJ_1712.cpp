#include <iostream>
using namespace std;
int main() {
	int a, b, c, i = 0;
	cin >> a >> b >> c;
	if (b >= c) {
		cout << "-1\n";
		return 0;
	}
	i = a / (c - b) + 1;
	if (i <= 0) cout << "-1\n";
	else cout << i << "\n";
}