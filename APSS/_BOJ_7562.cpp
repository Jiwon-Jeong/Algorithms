#include <cstdio>
#include <queue>
using namespace std;
int d[300][300];
int dx[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dy[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int l, fx, fy, tx, ty;
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &l);
		scanf("%d %d", &fx, &fy);
		scanf("%d %d", &tx, &ty);

		for (int i = 0; i < l; i++) {
			for (int j = 0; j < l; j++) {
				d[i][j] = -1;
			}
		}
		queue<pair<int, int>> q;
		q.push(make_pair(fx, fy));
		d[fx][fy] = 0;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			int cnt = d[x][y];
			q.pop();
			if (x == tx && y == ty) break;
			for (int i = 0; i < 8; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < l && ny >= 0 && ny < l) {
					if (d[nx][ny] == -1) {
						d[nx][ny] = cnt + 1;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
		
		printf("%d\n", d[tx][ty]);
	}
}