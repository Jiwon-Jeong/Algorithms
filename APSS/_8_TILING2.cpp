#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int cache[101];
int n;

int tiling(int x) {

	if (x <= 1) return 1;

	int& ret = cache[x];
	if (ret != -1) return ret;

	return (tiling(x - 2) + tiling(x - 1));
}

int main() {
	
	memset(cache, -1, sizeof(cache));
	cin >> n;
	
	cout << tiling(n) << endl;

}