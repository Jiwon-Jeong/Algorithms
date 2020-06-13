#include <string>
#include <vector>
#include <queue>
using namespace std;

void dfs(vector<vector<int>> computers, bool visit[], int x) {
	visit[x] = true;
	for (int i = 0; i < computers[x].size(); i++) {
		if (x == i) continue;
		if (computers[x][i] && !visit[i])
			dfs(computers, visit, i);
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	bool visit[n];
	fill(visit, visit + n, false);
	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			answer++;
			dfs(computers, visit, i);
		}
	}
	return answer;
}