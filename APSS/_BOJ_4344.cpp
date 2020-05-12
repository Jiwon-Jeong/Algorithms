#include <cstdio>
using namespace std;
int main() {
	int c;
	scanf("%d", &c);
	while (c--) {
		int n;
		double sum = 0, m = 0, cnt=0;
		scanf("%d", &n);
		int arr[1001];
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			sum += arr[i];
		}
		m = sum / n;
		for (int i = 0; i < n; i++) {
			if (arr[i] > m)
				cnt++;
		}
		printf("%.3f%%\n", cnt/n*100);
	}
}