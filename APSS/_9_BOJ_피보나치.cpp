#include <iostream>
#include<string.h>
using namespace std;

int dp[41];

int fib(int n) {
	if (n == 0) {
		dp[0] = 0;
		return 0;
	}
	if (n == 1) {
		dp[1] = 1;
		return 1;
	}
	int& ret = dp[n];
	if (ret != 0) return ret;

	return ret = fib(n - 1) + fib(n - 2);
}

int main() {
	int c;
	cin >> c;

	while (c-->0) {
		
		int n; 
		cin >> n;

		if (n == 0)
			cout << 1 << " " << 0 << endl;
		else if(n==1)
			cout << 0 << " " << 1 << endl;
		else {
			fib(n);
			cout << dp[n - 1] << " " << dp[n] << endl;
		}
	}

	return 0;
}