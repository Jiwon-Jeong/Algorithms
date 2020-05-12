#include <cstdio>
using namespace std;
int main() {
	int arr[42] = { 0 };
	int n = 10;
	while (n--) {
		int a;
		scanf("%d", &a);
		arr[a % 42]++;
	}
	int ans = 0;
	for (int i = 0; i < 42; i++) {
		if (arr[i] != 0)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}