#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int k;
	while (true) {
		scanf("%d", &k);
		if (k == 0) break; 
		vector<int> s(k);
		vector<int>c;
		for (int i = 0; i < k; i++)
			scanf("%d", &s[i]);
		sort(s.begin(), s.end());
		for (int i = 0; i < 6; i++) {
			c.push_back(0);
		}
		for (int i = 0; i < (k - 6); i++) {
			c.push_back(1);
		}
		vector<vector<int>> ans;
		do {
			vector<int> current;
			for (int i = 0; i < k; i++) {
				if (c[i] == 0) {
					current.push_back(s[i]);
				}
			}
			ans.push_back(current);
		} while (next_permutation(c.begin(), c.end()));
		sort(ans.begin(), ans.end());
		for (auto &v : ans) {
			for (int i = 0; i < v.size(); i++) {
				printf("%d ", v[i]);
			}
			printf("\n");
		}
		printf("\n");
	};
	return 0;
}