#include <iostream>
#include <algorithm>
using namespace std;

int n;
int tri[101][101]; // �Է� �� ������ �迭
int cache[101][101]; // memoization ����

int path(int x, int y) {

	// B: ���� �Ʒ����̸� 
	if (x == n - 1) return tri[x][y];

	//�湮�ؼ� ����� �ִ� ���
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