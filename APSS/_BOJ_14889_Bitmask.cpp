#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	int s[20][20];
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}
	int min = 1e9;
	for (int i = 0; i < (1 << n); i++) {
		int sum1 = 0, sum2 = 0, diff = 0;
		vector<int> first;
		vector<int> second;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				first.push_back(j);
			}
			else {
				second.push_back(j);
			}
		}
		if (first.size() != n / 2) continue;
		for (int j = 0; j < n/2; j++) {
			for (int k = 0; k < n / 2; k++) {
				if (j == k) continue;
				sum1 += s[first[j]][first[k]];
				sum2 += s[second[j]][second[k]];
			}
		}
		diff = sum1 - sum2;
		if (diff < 0) diff = -diff;
		min = min > diff ? diff : min;
	}
	cout << min << "\n";
	return 0;
}