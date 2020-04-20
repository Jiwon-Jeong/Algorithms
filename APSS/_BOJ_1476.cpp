#include <iostream>
using namespace std;
int main() {
	int e=0, s=0, m=0, b[16][29][20];
	for (int i = 0; i < 15*28*19; i++) {
		e = s = m = i;
		b[e % 15 + 1][s % 28 + 1][m % 19 + 1] = i+1;
	}
	cin >> e >> s >> m;
	cout << b[e][s][m] << "\n";
}