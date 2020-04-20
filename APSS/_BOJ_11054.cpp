#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	int a[1001], p[1001], m[1001];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < n; i++) {
		p[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j] && p[i] < p[j] + 1)
				p[i] = p[j] + 1;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		m[i] = 0;
		for (int j = n - 1; j > i; j--) {
			if (a[i] > a[j] && m[i] < m[j] + 1)
				m[i] = m[j] + 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(p[i] + m[i], ans);

	printf("%d", ans);
}