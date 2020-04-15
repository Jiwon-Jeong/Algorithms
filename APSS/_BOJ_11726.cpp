#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	int d[1001];
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		if (i <= 2) d[i] = i;
		else d[i] = (d[i - 1] + d[i - 2]) % 10007;
	}

	cout << d[n] << "\n";
}