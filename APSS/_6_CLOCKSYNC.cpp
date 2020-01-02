#include<iostream>
#include<vector>
#include<algorithm> //min() ��� ����
using namespace std;

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;
//vector<int> clocks�� ��ȣ ��

//����ġ�� �ð� �������
const char linked[SWITCHES][CLOCKS + 1] = {
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x.."
};

// ��� ���ν����� Ȯ��
bool areAligned(const vector<int>& clocks) {
	bool ret = true;
	for (int i = 0; i < 12; i++)
		if (!(clocks[i] == 12)) return false;

	return ret;
};

// �ð� ����ġ �ѹ� ������
void push(vector<int>& clocks, int swtch) {
	for (int clock = 0; clock < CLOCKS; clock++) {
		// ����Ǿ� �ִ� �ð� +3
		if (linked[swtch][clock] == 'x') {
			clocks[clock] += 3;
			if (clocks[clock] == 15) clocks[clock] = 3;
		}
	}
}

// �ּ� ��� ���ϱ�
int solve(vector<int>& clocks, int swtch) {
	//������ ����ġ���� �ߴµ� 12�ȵǸ� ���� 
	if (swtch == SWITCHES)
		return areAligned(clocks) ? 0 : INF;

	int ret = INF;
	for (int cnt = 0; cnt < 4; ++cnt) {
		// �ּڰ� ���ϱ�
		ret = min(ret, cnt + solve(clocks, swtch+1));
		push(clocks, swtch);
	}
	return ret;
}

void main() {
	int C, ans;
	vector<int> clocks(16);
	cin >> C;
	while (C-->0) {
		//�Է�
		for (int i = 0; i < 16; i++) {
			cin >> clocks[i];
		}
		ans = solve(clocks, 0);
		//�Ұ��� �ϸ� -1, �ƴϸ� ����� ���
		if (ans == INF) cout << -1 << endl;
		else cout << ans << endl;
	}
}