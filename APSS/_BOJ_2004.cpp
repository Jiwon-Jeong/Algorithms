#include <iostream>
using namespace std;

long long int i = 1;

int fiveCnt(int x) {
	int cnt = 0;

	for (i = 5; x / i >= 1; i *= 5) {
		cnt += x / i;
	}
	return cnt;
}

int twoCnt(int x) {
	int cnt = 0;

	for (i = 2; x / i >= 1; i *= 2) {
		cnt += x / i;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	int five = 0, two = 0;

	five += fiveCnt(n);
	if (m != 0) five -= fiveCnt(m);
	if (n != m) five -= fiveCnt(n - m);

	two += twoCnt(n);
	if (m != 0) two -= twoCnt(m);
	if (n != m) two -= twoCnt(n - m);

	cout << (two < five ? two : five )<< "\n";
	return 0;
}