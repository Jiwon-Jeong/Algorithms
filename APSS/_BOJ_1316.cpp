#include<iostream>
#include <string>
using namespace std;
int main() {
	int n, cnt=0;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		int flag = 0;
		int a[26] = { 0, };
		for (int i = 0; i < s.length(); i++) {
			if (i == s.length() - 1 && s[i]!=s[i-1] && a[s[i] - 'a'] == 1)
				flag = 1;

			if (i!=0 && s[i] != s[i - 1]) {
				if (a[s[i] - 'a'] == 1) {
					flag = 1; 
				}
			}
			a[s[i]-'a'] = 1;
		}
		if (flag == 0)cnt++;

	}
	cout << cnt << "\n";
}