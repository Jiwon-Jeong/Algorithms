#include <iostream>
#include <stack>
#include <string>

using namespace std;


int main() {
	int t, i=0;
	string result;
	cin >> t;
	cin.ignore();
	stack<int> s;
	while(t--) {
		int k;
		cin >> k;
		if (k > i) {
			while (k > i) {
				s.push(++i);
				result += '+';
			}
			s.pop();
			result += '-';
		}
		else {
			bool found = false;
			if (!s.empty()) {
				int top = s.top();
				s.pop();
				result += '-';
				if (k == top)
					found = true;
			}if (!found) {
				cout << "NO" << '\n';
				return 0;
			}
		}
	}

	for (char x : result) {
		cout << x << '\n';
	}
	return 0;
}