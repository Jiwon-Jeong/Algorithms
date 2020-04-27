#include <cstdio>
#include <queue>
using namespace std;
int n, m;
int t[1000][1000];
int d[1000][1000];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int cnt = 0, day = 0, total = 0;

int main() {
	scanf("%d %d", &m, &n);
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &t[i][j]);
			d[i][j] = -1;
			if (t[i][j] == 1) {
				q.push(make_pair(i, j));
				d[i][j] = 0;
			}
			if (t[i][j] == 0)
				total++;
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		day = d[x][y];
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n &&ny >= 0 && ny < m) {
				if (d[nx][ny] == -1 && t[nx][ny] == 0) {
					d[nx][ny] = day + 1;
					t[nx][ny] = 1;
					q.push(make_pair(nx, ny));
					cnt++;
				}
			}
		}
	}
	if (total != cnt) {
		printf("-1\n");
	}
	else {
		int max = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				max = max < d[i][j] ? d[i][j] : max;
			}
		}
		printf("%d\n", max);
	}

}