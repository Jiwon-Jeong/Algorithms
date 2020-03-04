#include <iostream>
#include <stack>
#include <string>
using namespace std;

string solution(string str) {
	stack<char> s;
	for (char ch : str) {
		if (ch == ')') {
			if (s.empty()) {
				return "NO";
			}
			else s.pop();
		}
		else
			s.push(ch);
	}
	if (s.empty()) return "YES";
	else return "NO";
}


int main() {
	int t;
	cin >> t;
	cin.ignore();
	while (t--) {
		string str, result;
		getline(cin, str);
		cout << solution(str) << '\n';
	}
	return 0;
}
