#include <cstdio>
#include <queue>
using namespace std;
int n, m;
int a[100][100];
int check[100][100];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]);
			check[i][j] = 0;
		}
	}
	queue<pair<int, int>> q;
	check[0][0] = 1;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		int x = q.front().first; 
		int y = q.front().second;
		q.pop();
		int cnt = check[x][y];
		if (x == n - 1 && y == m - 1) break;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (check[nx][ny]==0 && a[nx][ny] == 1) {
					check[nx][ny] = cnt + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	printf("%d\n", check[n-1][m-1]);
	return 0;
}