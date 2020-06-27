class Solution {
public:
	int numSquares(int n) {
		vector<int> v(n + 1);
		for (int i = 1; i <= n; i++) v[i] = i;
		for (int i = 2; i <= n; i++) {
			for (int j = 2; j*j <= i; j++) {
				v[i] = min(v[i], v[i - j * j] + 1);
			}
		}
		return v[n];
	}
};