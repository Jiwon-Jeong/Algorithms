#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	int al[26] = { 2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9 };
	int ans = 0;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		ans += al[s[i] - 'A']+1;
	}
	cout << ans << "\n";
}