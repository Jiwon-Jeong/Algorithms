#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

char s[101];
stack<char> op;

int priority(char c) {
	if (c == '*' || c == '/') return 2;
	else if (c == '+' || c == '-') return 1;
	else return 0;
}

void solve() {
	for (int i = 0; i < (int)strlen(s); i++) {
		char &c = s[i];
		if ('A' <= c && c <= 'Z') printf("%c", c);
		else if (c == '(') op.push(c);
		else if (c == ')') {
			while (op.top() != '(') {
				printf("%c", op.top());
				op.pop();
			}
			op.pop();
		}
		else {
			while (!op.empty() && (priority(c) <= priority(op.top()))) {
				printf("%c", op.top());
				op.pop();
			}
			op.push(c);
		}
	}
	while (!op.empty()) {
		printf("%c", op.top());
		op.pop();
	}
	printf("\n");
}

int main() {
	scanf("%s", s);
	solve();
	return 0;
}


ÃâÃ³: https://rebas.kr/730 [PROJECT REBAS]