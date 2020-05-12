#include <cstdio>
using namespace std;
int main() {
	int n;
	float arr[1000] = { 0 };
	float sum = 0, m = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%f", &arr[i]);
		if (m < arr[i])m = arr[i];
	}

	for (int i = 0; i < n; i++) {
		arr[i] = arr[i] / m *100;
		sum += arr[i];
	}
	printf("%f\n", sum /n);
}