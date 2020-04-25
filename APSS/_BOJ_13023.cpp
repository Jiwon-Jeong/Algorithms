#include <iostream>
#include <vector>
using namespace std;
vector<int> v[2000];
int n, m;
int check[2000];
int ans = 0;

void go(int index, int cnt) {
	if (cnt == 5) {
		ans = 1;
		return;
	}
	check[index] = 1;
	for (int i = 0; i < v[index].size(); i++) {
		int next = v[index][i];
		if (check[next]) continue;
		go(next, cnt+1);
		if (ans == 1) return;
	}
	check[index] = 0;
}

int main() {
	int a, b;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	for (int i = 0; i < n; i++) {
		go(i, 1);
		if (ans) {
			cout << 1 << "\n";
			return 0;
		}
	}
	cout << 0 << "\n";
	return 0;
}