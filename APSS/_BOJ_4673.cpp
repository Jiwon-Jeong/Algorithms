#include <cstdio>
bool arr[10001] = { false };
void make(int a) {
	if (a > 10000) return;
	int next = a;
	while (true) {
		if (a < 10) {
			next += a % 10;
			break;
		}
		next += a % 10;
		a /= 10;
	}
	if (arr[next] != true) {
		arr[next] = true;
		return make(next);
	}
	return;
}
int main() {
	for (int i = 1; i <= 10000; i++) {
		make(i);
	}

	for (int i = 1; i <= 10000; i++) {
		if (!arr[i])
			printf("%d\n", i);
	}
}