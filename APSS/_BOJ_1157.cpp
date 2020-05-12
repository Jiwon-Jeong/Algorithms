#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	string s;
	cin >> s;
	int a[26] = { 0, };
	int max = 0, idx =0;
	bool flag = false;
	for (int i = 0; i < s.length(); i++) {
		s[i] = toupper(s[i]);
		a[s[i] - 'A']++;
	}
	
	for (int i = 0; i < 26; i++) {
		if (a[i] > max) {
			max = a[i]; idx = i;
		}
	}

	for (int i = 0; i < 26; i++) {
		if (i!=idx && a[i] == max)
			flag = true;
	}

	if (flag) cout<<"?" <<"\n";
	else cout<<char(idx+'A')<<"\n";
	return 0;
}