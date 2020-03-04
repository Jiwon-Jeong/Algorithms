#include<iostream>
#include <vector>
using namespace std;

const int coverType[4][3][2] = {
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{0,1}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,-1},{1,0}}
};

//board�� ���� �� ���� �ؾߵǴϱ� �����ͷ�

/*set: ����� ���ų� ����ų� - delta*/
bool set(vector<vector<int>>& board, int y, int x, int type, int delta) {
	bool ok = true;
	for (int i = 0; i < 3; i++) {
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];

		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
			ok = false;
		//��� ���� ������ �� �ڸ��� ��� �ִٸ�
		else if ((board[ny][nx] += delta) > 1)
			ok = false;
	}

	return ok;
}

/*cover: ��� ���� ��� ������*/
int cover(vector<vector<int>>& board) {
	//���� ��ä�� ĭ �� ���� ��/�� ã�� 
	int y = -1, x = -1;
	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board[i].size(); ++j) {

			if (board[i][j] == 0) { // 0:��� �ȵ��� ĭ
				y = i;
				x = j;
				break;
			}
		}
		//b:����ĭ�̸� �н�
		if (y != -1) break;
	}

	//b:��� ĭ ä�������� ��
	if (y == -1) return 1;

	//��ġ ã������ �����ž�
	int ret = 0;

	for (int type = 0; type < 4; ++type) {
		//���� �� ������ ���� ��������� ����
		if (set(board, y, x, type, 1)) {
			ret += cover(board);
		}
		//�������� ����
		set(board, y, x, type, -1);
	}

	return ret;

}


void main() {

	int C, H,W, n=0, t;

	cin >> C >> H >> W;

	vector<vector<int>> board(H, vector<int>(W));

	while (--C >= 0) {
		
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> t;
				board[i][j] = t;

				if (t == 0)
					n++;
			}
		} 

		if (!(n % 3 == 0)) cout << 0<<endl;
		else
			cout << cover(board);
		
	}

}