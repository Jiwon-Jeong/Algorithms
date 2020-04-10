#include <iostream>
#include<stack>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> ngf(n);
	vector<int>f(1000000);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		f[a[i]] += 1;
	}
	stack<int>st;
	st.push(0);
	for (int i = 1; i < n; i++) {
		if (st.empty()) {
			st.push(i);
		}
		
		while (!st.empty() && f[a[i]] > f[a[st.top()]]) {
			ngf[st.top()] = a[i];
			st.pop();
		}

		st.push(i);
	}
	while (!st.empty()) {
		ngf[st.top()] = -1;
		st.pop();
	}
	for (int i = 0; i < n; i++) {
		cout << ngf[i] << ' ';
	}
	cout << '\n';
	return 0;
}