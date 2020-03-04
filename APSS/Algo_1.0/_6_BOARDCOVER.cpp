#include<iostream>
#include <vector>
using namespace std;

const int coverType[4][3][2] = {
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{0,1}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,-1},{1,0}}
};

//board는 직접 값 변경 해야되니까 포인터로

/*set: 블록을 놓거나 지우거나 - delta*/
bool set(vector<vector<int>>& board, int y, int x, int type, int delta) {
	bool ok = true;
	for (int i = 0; i < 3; i++) {
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];

		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
			ok = false;
		//블록 놓고 싶은데 그 자리에 블록 있다면
		else if ((board[ny][nx] += delta) > 1)
			ok = false;
	}

	return ok;
}

/*cover: 어디에 무슨 블록 놓을지*/
int cover(vector<vector<int>>& board) {
	//아직 안채운 칸 중 가장 왼/위 찾기 
	int y = -1, x = -1;
	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board[i].size(); ++j) {

			if (board[i][j] == 0) { // 0:블록 안덮인 칸
				y = i;
				x = j;
				break;
			}
		}
		//b:덮인칸이면 패스
		if (y != -1) break;
	}

	//b:모든 칸 채워졌으면 끝
	if (y == -1) return 1;

	//위치 찾았으면 덮을거야
	int ret = 0;

	for (int type = 0; type < 4; ++type) {
		//덮을 수 있으면 놓고 재귀적으로 수행
		if (set(board, y, x, type, 1)) {
			ret += cover(board);
		}
		//못덮으면 지워
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