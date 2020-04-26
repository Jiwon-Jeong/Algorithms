#include <iostream>
#include<vector>
#include <queue>
using namespace std;
vector<int> g[1001];
int check[1001];
int n, m, cnt = 0;

void bfs(int start) {
	if (check[start]) return;
	cnt+=1;
	queue<int> q;
	check[start] = true; q.push(start);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < g[x].size(); i++) {
			int next = g[x][i];
			if (!check[next]) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}
int main() {
	cin >> n >>m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for (int i = 1; i <= n; i++ ) {
		bfs(i);
	}
	
	cout << cnt << "\n";
	return 0;
}
