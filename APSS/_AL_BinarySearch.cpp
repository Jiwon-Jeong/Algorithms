#include <stdio.h>
using namespace std;

int find(int arr[], int size,  int key) {
	int l = 0, r = size, idx = 0;
	while (true) {
		idx = (l + r) / 2;
		if (arr[idx] == key) break;
		if (arr[idx] < key) l = idx + 1;
		else r = idx - 1;
	}
	return idx;
}

int main() {
	int arr[10] = { 1, 22, 33, 35, 46, 57, 88, 100};
	int size = sizeof(arr) / sizeof(arr[0]) - 1;

	printf("%d\n", find(arr, size, 57));
}