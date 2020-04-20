#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int  a[9],sum=0;
	bool flag = false;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	sort(a, a + 9);
	for (int i = 0; i < 9; i++) {
		for (int j = i+1; j < 9; j++) {
			if (sum - a[i] - a[j] == 100 && i != j) {
				a[i] = a[j] = 0;
				flag = true;
				break;
			}
		}
		if (flag)
			break;
	}
	sort(a, a + 9);
	for (int i = 0; i < 9; i++) {
		if (a[i] != 0)
			printf("%d\n", a[i]);
	}
}