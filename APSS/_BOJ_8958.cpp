#include <iostream>
#include <string>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int cnt = 0, sum = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'O') {
				cnt++;
				sum += cnt;
				if (i == s.length() - 1) break;
				if (s[i + 1] == 'X') {
					cnt = 0;
				}

			}
		}
		cout << sum<<"\n";
	}
}