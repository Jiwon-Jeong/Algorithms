#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	stack<int> st;
	vector<int> ans(n);
	vector<int>a(n);
	st.push(0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for(int i=1; i<n; i++){
		if (st.empty())
			st.push(i);
		
		while (!st.empty() && a[st.top()] < a[i]) {
			ans[st.top()] = a[i];
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty()) {
		ans[st.top()] = -1;
		st.pop();
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return 0;
	
}