#include <iostream>
#include <vector>
#include <string>
using namespace std;

void sol(vector<string> &v, string ans, int l, int r, int n) {
	//Á¾·á 
	if (ans.length() == 2 * n) {
		v.push_back("\"" + ans + "\"");
		return;
	}
	if (l < n)
		sol(v, ans + "(", l + 1, r, n);
	if (r < l)
		sol(v, ans + ")", l, r + 1, n);
	return;
}

int main() {
	int n, cnt;
	vector<string> v;
	cin >> n;
	sol(v, "", 0, 0, n);
	cout << "[";
	for (int i = 0; i < v.size() - 1; i++)
		cout << v[i] << ", ";
	cout << v.back() << "]" << endl;

	return 0;
}