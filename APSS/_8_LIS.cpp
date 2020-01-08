#include <iostream>
#include <algorithm>
using namespace std;

int n;
int cache[100], S[100];

int lis(int i) {

	int& ret = cache[i+1];
	if (ret != -1) return ret;

	ret = 1;
	for (int j = i+1; j < n; ++j) {
		if (i==-1 || S[i] <  S[j])
			ret = max(ret, lis(j) + 1);
	}
	return ret;
}

void main() {
	memset(cache, -1, sizeof(cache));
	S[-1] = -100000;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> S[i];
	}
	cout<<lis(-1)-1<<endl;
}