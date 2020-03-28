#include <string>
#include <stack>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	stack<char> stack;
	string str;
	int i = 0;
	int sum = 0;
	int mul = 1;

	cin >> str;

	for (i = 0; i < str.length(); i++) {
		char temp = str[i];

		if (temp == '(') {
			mul *= 2;
			stack.push(temp);
			if (i + 1 < str.length() && str[i + 1] == ')') sum += mul;
		}
		else if (temp == '[') {
			mul *= 3;
			stack.push(temp);
			if (i + 1 < str.length() && str[i + 1] == ']') sum += mul;
		}

		if (!stack.empty()) {
			if (temp == ')') {
				mul /= 2;
				if (stack.top() == '(') stack.pop();
			}
			else if (temp == ']') {
				mul /= 3;
				if (stack.top() == '[') stack.pop();
			}
		}
	}

	if (!stack.empty())
		sum = 0;

	cout << sum;

	return 0;
}