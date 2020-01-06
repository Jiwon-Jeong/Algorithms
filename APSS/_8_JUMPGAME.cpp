#include<iostream>
#include<string.h>
using namespace std;

int n, board[100][100];
int cache[100][100];

int jump(int y, int x) {
	// B: �Ǻ��� ū ������ ��� ��
	if (y >= n || x >= n) return 0;
	// B: ��ĭ�� �����ϸ� ��
	if (y == n - 1 && x == n - 1) return 1;

	// Memoization
	// �湮�ߴ� ���̸�

	if (cache[y][x] != -1)
		return cache[y][x];

	cache[y][x] = (jump(y + board[y][x], x) || jump(y, x + board[y][x]));

	return cache[y][x];
}

int main() {

	cin >> n;

	// cache, board -1�� �ʱ�ȭ 
	memset(cache, -1, sizeof(cache));
	memset(board, -1, sizeof(board));

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			cin >> board[i][j];

	cout<<jump(0, 0)<<endl;

	return 0;
}