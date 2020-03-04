#include <iostream>
#include <algorithm>
using namespace std;

int n;
int tri[101][101]; // 입력 값 저장할 배열
int cache[101][101]; // memoization 위해

int path(int x, int y) {

	// B: 가장 아랫줄이면 
	if (x == n - 1) return tri[x][y];

	//방문해서 결과값 있는 경우
	int& ret = cache[x][y];
	if (ret != -1)
		return ret;

	return	ret = tri[x][y] + max(path(x + 1, y), path(x + 1, y + 1));

}

void main() {
	memset(cache, -1, sizeof(cache));
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			cin >> tri[i][j];


	cout << path(0, 0) << endl;
}