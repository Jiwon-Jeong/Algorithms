#include <stdio.h>
int main() {
	int n, a[100001], l[100001], max = -1001;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < n; i++) {
		l[i] = a[i];
		if (l[i] < l[i - 1] + l[i])
			l[i] = l[i - 1] + l[i];

		max = l[i] > max ? l[i] : max;
	}
	printf("%d\n", max);
	return 0;
}