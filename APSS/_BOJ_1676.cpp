#include <iostream>
using namespace std;

int main() {

	int n, cnt=0 ,j=1;
	cin >> n;
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	
	while (j<n) {
		j *= 5;
		cnt += n/j;
	}
	cout << cnt << "\n";
	
	return 0;
}