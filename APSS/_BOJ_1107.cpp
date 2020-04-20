#include <iostream>
using namespace std;
bool broken[10];
int possible(int c) {
	if (c == 0) {
		return broken[0] ? 0 : 1;
	}
	int len = 0;
	while (c > 0) {
		if (broken[c % 10]) return 0;
		len++;
		c /= 10;
	}
	return len;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		broken[x] = true;
	}
	int ans = n - 100;
	if (ans < 0) {
		ans = -ans;
	}
	for (int i = 0; i <= 1000000; i++) {
		int c = i;
		int len = possible(c);
		if (len > 0) { // 0 아니면
			int press = c - n; //현재 bf중인 친구랑 가려는 채널 차 구해
			if (press < 0) {
				press = -press;
			}
			if (ans > len + press) {
				ans = len + press;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}