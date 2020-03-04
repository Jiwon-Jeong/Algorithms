#include <iostream>
using namespace std;

const int dx[8] = { -1,-1,-1,1,1,1,0,0 };
const int dy[8] = { -1,0,1,-1,0,1,-1,1 };
char board[5][5];

bool inRange(int y, int x) {
	if (y < 0 || y>4 || x < 0 || x>4) return false;
	return true;
}

bool hasWord(int y, int x, const string& word) {

	//기저사례
	if (!inRange(y, x)) return false;
	if (board[y][x] != word[0]) return false;
	if (word.size() == 1) return true;

	//성공 조건
	for (int direction = 0; direction < 8; direction++) {
		int nextX = x + dx[direction], nextY = y + dy[direction];

		if (hasWord(nextY, nextX, word.substr(1))) return true;
	}

	//아니면 모두 fail
	return false;
}

/*
void main() {

	for (int i = 0; i < 5; i++)
		cin >> board[i];
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		char word[11];
		cin >> word;

		bool isOK = false;
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++)
				if (hasWord(j, k, word)) {
					isOK = true;
					break;
				}

			if (isOK) break;
		}

		if (isOK)
			cout << word << " YES";
		else
			cout << word << " NO";
		cout << endl;
	}

}
*/