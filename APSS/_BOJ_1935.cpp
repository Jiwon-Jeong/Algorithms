#include<cstdio>
#include<stack>
#include<cstring>
#define MAX 100000

using namespace std;
typedef long double ld;
ld value[26] = { 0, };

char expr[MAX] = { 0, };
int main() {
	ld result = 0;
	stack<ld> s;
	int N = 0; scanf("%d", &N);
	scanf("%s", expr);
	for (int i = 0; i < N; i++) {
		scanf("%Lf", &value[i]);
	}
	int slen = strlen(expr);
	for (int i = 0; i < slen; i++) {
		ld tmp;
		if ('A' <= expr[i] && expr[i] <= 'Z') {
			s.push(value[expr[i] - 'A']);
		}
		else {
			tmp = s.top(); s.pop();
			switch (expr[i]) {
			case '+': tmp = tmp + s.top(); s.pop(); break;
			case '-': tmp = s.top() - tmp; s.pop(); break;
			case '*': tmp = tmp * s.top(); s.pop(); break;
			case '/': tmp = s.top() / tmp; s.pop(); break;
			}
			s.push(tmp);
		}
		result = s.top();
	}
	printf("%.2Lf\n", result);
	return 0;
}
