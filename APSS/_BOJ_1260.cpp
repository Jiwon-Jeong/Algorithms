#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> g[1001];
bool check[1001];
int n, m, v;

void dfs(int x) {
	check[x] = true;
	cout << x << " ";
	for (int i = 0; i < g[x].size(); i++) {
		int next = g[x][i];
		if (check[next]) continue;
		dfs(next);
	}
}

void bfs() {
	queue<int> q;
	check[v] = false; q.push(v);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		cout << x << " ";
		for (int i = 0; i < g[x].size(); i++) {
			int next = g[x][i];
			if (check[next] == true) {
				check[next] = false;
				q.push(next);
			}
		}
	}
}

int main() {
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	for (int i = 0; i < n; i++) {
		sort(g[i].begin(), g[i].end());
	}

	dfs(v); cout << "\n";
	bfs(); cout << "\n";
	return 0;
}