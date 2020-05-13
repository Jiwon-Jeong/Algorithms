#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.length(); i++) {
		if (i == s.length() - 1) {
			cnt++;	break;
		}
		if (s[i] == 'c') {
			if (s[i + 1] == '-' || s[i + 1] == '=') {
				cnt++; i++; continue;
			}
		}
		if (s[i] == 's' || s[i] == 'z') {
			if (s[i + 1] == '=') {
				cnt++; i++; continue;
			}
		}
		if (s[i] == 'l' || s[i] == 'n') {
			if (s[i + 1] == 'j') {
				cnt++; i++; continue;
			}
		}
		if (s[i] == 'd' && s[i + 1] == '-') {
			cnt++; i++; continue;
		}
		if (i != s.length() - 2 && s[i] == 'd' && s[i + 1] == 'z'&&s[i + 2] == '=') {
			cnt++; i += 2; continue;
		}
		cnt++;
	}
	cout << cnt << "\n";
}