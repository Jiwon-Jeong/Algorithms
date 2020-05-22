#include <cstdio>
int main() {
	int arr[9] = { 0 };
	int max=0, idx=0;
	for(int i=0; i<9; i++){
		scanf("%d", &arr[i]);
		if (max < arr[i]) {
			max = arr[i];
			idx = i+1;
		}
	}
	printf("%d\n%d", max, idx);
}