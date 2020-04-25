#include <stdio.h>
#include <cstring>
#include <string>
using namespace std;
int main() {
	int m;
	int s = 0;
	int n = 20;
	int x;
	char op[10];
	scanf("%d", &m);
	while (m--) {
		scanf("%s", op);
		if (!strcmp(op, "all")){
			s = (1 << n) - 1;
		}
		else if (!strcmp(op, "empty")) {
			s = 0;
		}
		else if (!strcmp(op, "add")) {
			scanf("%d", &x); x--;
			s = (s | (1 << x));
		}
		else if (!strcmp(op, "check")) {
			scanf("%d", &x); x--;
			if ((s & (1 << x)) == 0) {
				printf("0\n");
			}
			else
				printf("1\n");
		}
		else if (!strcmp(op, "remove")) {
			scanf("%d", &x); x--;
			s = (s & ~(1 << x));
		}
		else if (!strcmp(op, "toggle")) {
			scanf("%d", &x); x--;
			s = (s ^ (1 << x));
		}
	}
	return 0;
}