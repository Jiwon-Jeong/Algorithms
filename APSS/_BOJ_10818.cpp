#include <cstdio>
#include <vector>
using namespace std;
int main() {
	int n, max=-1000000 ,min=1000000;
	scanf("%d", &n);
	vector<int> arr;
	while (n--) {
		int a;
		scanf("%d", &a);
		if (a < min) min = a;
		if (a > max)max = a;
	}
	printf("%d %d", min, max);
}