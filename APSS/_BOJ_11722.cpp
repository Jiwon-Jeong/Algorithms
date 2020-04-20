#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int a[1001], d[1001];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		d[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[i] < a[j] && d[i] < d[j] +1)
				d[i] = d[j] + 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = ans > d[i] ? ans : d[i];

	printf("%d", ans);
}