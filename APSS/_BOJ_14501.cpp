#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int t[16];
int p[16];
int ans=0;
int n;
void go( int i, int sum) {
	if (i == n) {
		if (ans < sum) ans = sum;
		return;
	}
	if (i > n) return ;
	go(i+1, sum);
	go(i + t[i], sum + p[i]);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t[i];
		cin >> p[i];
	}
	go( 0, 0);
	cout << ans<<"\n";
	return 0;
	
}