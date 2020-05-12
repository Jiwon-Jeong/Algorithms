#include <cstdio>
using namespace std;
int main() {
	int a, b, c;
	int res;
	int arr[10] = {0};
	scanf("%d %d %d", &a, &b, &c);
	res = a * b * c;
	while (true) {
		if (res < 10) { arr[res % 10]++;  break; }
		arr[res % 10]++;
		res /= 10;
	}

	for (int i = 0; i < 10; i++)
		printf("%d\n", arr[i]);
}