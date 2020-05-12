#include <iostream>
#include <string>
using namespace std;
int main() {
	int cnt = 0;
	string s;
	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ')
			cnt++;
	}
	if (s[0] == ' ') cnt--;
	if (s[s.length() - 1] == ' ')
		cnt--;
	cout << cnt+1 << "\n";
}