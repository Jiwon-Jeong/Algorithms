#include <iostream>
#include <vector>
using namespace std;
bool flag;

void dfs(int x, vector<int> g[], vector<int> &check) {
	if (check[x] == 0) check[x] = 1;
	int team_x = check[x];
	for (int i = 0; i < g[x].size(); i++) {
		int next = g[x][i];
		int group = check[next];
		if (group == 0) { //팀이 아직 없으면 정해주고 dfs계속
			check[next] = team_x == 1 ? 2 : 1;
			dfs(next, g, check);
		}
		else { // 팀 있는데 맞으면 패스 아니면 리턴
			if (team_x != group) continue;
			else { flag = false; return; }
		}
	}
}

int main() {
	int k;
	cin >> k;
	while (k--) {
		int v, e;
		cin >> v >> e;
		vector<int> g[20001];
		vector<int> check(v+1, 0);
		for (int i = 0; i < e; i++) {
			int a, b;
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		flag = true;
		for (int i = 1; i <= v; i++) {
			dfs(i, g, check);
		}
		if (flag == false) {
			cout << "NO\n";
		}
		else
			cout << "YES\n";
	}
	return 0;
}