#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;
	int a[27];
	for (int i = 1; i < 27; i++)
		a[i] = -1;
	for (int i = 0; i < s.length(); i++) {
		if(a[s[i] - 96]==-1)
			a[s[i] - 96] = i;
	}
	for (int i = 1; i < 27; i++)
		printf("%d ", a[i]);
}