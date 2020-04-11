#include <iostream>

using namespace std;

bool prime(int n) {
	if (n < 2) return false;
	for (int i = 2; i*i <= n; i++) {
		if (n%i == 0) return false;
	}
	return true;
}

int main() {
	int n,a, cnt=0;
	cin >> n;
	while (n-- > 0) {
		cin >> a;
		if (prime(a)) cnt+=1;
	}
	cout << cnt << "\n";
}