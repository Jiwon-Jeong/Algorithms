#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
bool check(string& password) {
	int ja = 0;
	int mo = 0;
	for (char x : password) {
		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
			mo++;
		else
			ja++;
	}
	if (ja >= 2 && mo >= 1)
		return true;
	return false;
}

void go(int n, vector<char> &ch, string password, int i) {
	if (password.length() == n) {
		if(check(password))
			cout << password << "\n";
		return;
	}
	if (i >= ch.size())
		return;

	go(n, ch, password + ch[i], i + 1);
	go(n, ch, password, i + 1);
}
int main() {
	int l, c;
	cin >> l >> c;
	vector<char> ch(c);
	for (int i = 0; i < c; i++) {
		cin >> ch[i];
	}
	sort(ch.begin(), ch.end());
	go(l, ch, "", 0);
}