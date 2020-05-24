#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int c[300][300];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int n, h;
void bfs(int x, int y, vector<vector<int>> &land, int cnt) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	c[x][y] = cnt;
	while (!q.empty()) {
		x = q.front().first; y = q.front().second;
		q.pop();
		cout << x << " " << y << " " << cnt << endl;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k]; int ny = y + dy[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
				if (c[nx][ny] == 0 && abs(land[nx][ny] - land[x][y]) <= h) {
					q.push(make_pair(nx, ny));
					c[nx][ny] = cnt;

				}
			}
		}
	}
}

int solution(vector<vector<int>> land, int height) {
	int answer = 0;
	int cnt = 0;
	n = land.size(); h = height;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (c[i][j] == 0) {
				bfs(i, j, land, ++cnt);
			}
		}
	}




	return cnt;
}