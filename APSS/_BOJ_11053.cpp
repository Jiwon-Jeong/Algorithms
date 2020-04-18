#include <stdio.h>
int main() {
	int n, a[1001], l[1001], max=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	for (int i = 0; i < n; i++) {
		l[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && l[i] < l[j] + 1)
				l[i] = l[j] + 1;
		}
		max = l[i] > max ? l[i] : max;
	}
	printf("%d\n", max);
	return 0;
}