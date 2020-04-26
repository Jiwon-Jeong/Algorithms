#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int dx[] = { 0,0,1,-1,1,1,-1,-1 };
int dy[] = { 1,-1,0,0,1,-1,1,-1 };
int w, h;
int a[100][100];
int d[100][100];
void bfs( int x, int y, int cnt) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	d[x][y] = cnt;

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int k = 0; k < 8; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
				if (a[nx][ny] == 1 && d[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					d[nx][ny] = cnt;
				}
			}
		}
	}
}

int main() {

	while (scanf("%d %d", &w, &h) == 2) {
		if (w == 0 && h == 0) break;
		if (w == 1) {
			int x;
			scanf("%d", &x);
			printf("%d\n", x);
			continue;
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%1d", &a[i][j]);
				d[i][j] = 0;
			}
		}
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (a[i][j] == 1 && d[i][j] == 0) {
					bfs(i, j, ++cnt);
				}
			}
		}
		printf("%d\n", cnt);
		
	}
}