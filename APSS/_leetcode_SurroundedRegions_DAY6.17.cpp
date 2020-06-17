class Solution {
public:

	void DFS(vector<vector<char>>& board, int x, int y) {
		// 종료조건: 범위 벗어나거나 X인 경우
		if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != 'O') return;

		board[x][y] = 'C';
		// 범위에 속하는데 O인 경우
		DFS(board, x - 1, y);
		DFS(board, x, y + 1);
		DFS(board, x + 1, y);
		DFS(board, x, y - 1);
	}

	void solve(vector<vector<char>>& board) {
		int m = board.size(); //row
		if (m == 0) return;
		int n = board[0].size();  //col

		for (int i = 0; i < m; i++) {
			if (board[i][0] == 'O')
				DFS(board, i, 0);
			if (board[i][n - 1] == 'O')
				DFS(board, i, n - 1);
		}
		for (int l = 0; l < n; l++) {
			if (board[0][l] == 'O')
				DFS(board, 0, l);
			if (board[m - 1][l] == 'O')
				DFS(board, m - 1, l);
		}

		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				if (board[j][k] == 'O')
					board[j][k] = 'X';
				if (board[j][k] == 'C')
					board[j][k] = 'O';
			}
		}
	}
};