#include <iostream>
using namespace std;
int arr[5];

void quicksort( int i, int j) {

	if (i >= j) return;
	int pivot = (i + j) / 2;
	int l = i, r = j;
	while (l<=r) {
		while (arr[l] < arr[pivot] ) l++;
		
		while (arr[r] > arr[pivot]) r--;

		if (l <= r) {
			swap(arr[l], arr[r]);
			l++; r--;
		}
	}
	quicksort( i, r);
	quicksort( l, j);
}

int main() {
	for (int i = 0; i < 5; i++)
		scanf("%d", &arr[i]);
	quicksort(0, 4);
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}