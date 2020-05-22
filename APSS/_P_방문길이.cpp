#include <string>
#include <iostream>
using namespace std;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int a[11][11][11][11];
int solution(string dirs) {
	int answer = 0;
	int x = 5, y = 5, nx = 0, ny = 0, i = 0;
	while (i < dirs.length()) {
		switch (dirs[i]) {
		case 'U':
			nx = x + dx[0]; ny = y + dy[0];
			break;
		case 'D':
			nx = x + dx[1]; ny = y + dy[1];
			break;
		case 'L':
			nx = x + dx[2]; ny = y + dy[2];
			break;
		case 'R':
			nx = x + dx[3]; ny = y + dy[3];
			break;
		}
		if (nx >= 0 && nx <= 10 && ny >= 0 && ny <= 10) { //범위 안이고
			if (a[x][y][nx][ny] == 0) { // 아직 안지나간 길이면
				//이동하기
				answer++;
				a[x][y][nx][ny] = 1;
				a[nx][ny][x][y] = 1;
			}
			x = nx; y = ny;
		}
		i++;
	}
	return answer;
}