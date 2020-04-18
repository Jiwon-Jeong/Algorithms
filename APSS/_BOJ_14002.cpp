#include <stdio.h>
int a[1001];
int p[1001];
void find(int x) {
	if (x == -1) return;
	find(p[x]);
	printf("%d ", a[x]);
}
int main() {
	int n, l[1001], max = 0, ind=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < n; i++) {
		l[i] = 1;
		p[i] = -1;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && l[i] < l[j] + 1) {
				l[i] = l[j] + 1;
				p[i] = j;
			}
		}
		if (max < l[i]) {
			max = l[i];
			ind = i;
		}
	}
	printf("%d\n", max);
	find(ind);
	return 0;
}