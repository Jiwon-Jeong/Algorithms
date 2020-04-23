#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find(vector<int> &a) {
	int ans = 0;
	for (int i = 1; i < a.size(); i++) {
			ans += abs(a[i-1] - a[i]);
	}

	return ans;
}
int main() {
	int n, max = 0;
	cin >> n;
	vector<int> a(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	do {
		int tmp = find(a);
		if (max < tmp)
			max = tmp;
	} while (next_permutation(a.begin(), a.end()));
	cout << max << "\n";
}