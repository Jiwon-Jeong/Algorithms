#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	string s;
	cin >> s;
	stack<char> s1;
	stack<char> s2;
	int n = s.length(), i=0;

	while (n-- > 0) {
		s1.push(s.at(i++));
	}
	cin >> i;
	cin.ignore();
	while (i--) {
		char op;
		cin >> op;
		switch (op) {
		case 'L':
			if (!s1.empty()) {
				char ch = s1.top();
				s2.push(ch);
				s1.pop();
			}
			break;
		case 'D':
			if (!s2.empty()) {
				char ch = s2.top();
				s1.push(ch);
				s2.pop();
			}
			break;
		case 'B':
			if (!s1.empty()) {
				s1.pop();
			}
			break;
		case 'P':
			char newChar;
			cin >> newChar;
			cin.ignore();
			s1.push(newChar);
			break;
		}
	}

	while (!s1.empty()) {
		s2.push(s1.top());
		s1.pop();
	}

	string result;
	while (!s2.empty()) {
		result += s2.top();
		s2.pop();
	}

	cout << result << '\n';
	return 0;
}
