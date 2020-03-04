#include<iostream>
#include<vector>
#include<algorithm> //min() 사용 위해
using namespace std;

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;
//vector<int> clocks는 번호 수

//스위치랑 시계 연결관계
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

// 모두 열두시인지 확인
bool areAligned(const vector<int>& clocks) {
	bool ret = true;
	for (int i = 0; i < 12; i++)
		if (!(clocks[i] == 12)) return false;

	return ret;
};

// 시계 스위치 한번 누른거
void push(vector<int>& clocks, int swtch) {
	for (int clock = 0; clock < CLOCKS; clock++) {
		// 연결되어 있는 시계 +3
		if (linked[swtch][clock] == 'x') {
			clocks[clock] += 3;
			if (clocks[clock] == 15) clocks[clock] = 3;
		}
	}
}

// 최소 경우 구하기
int solve(vector<int>& clocks, int swtch) {
	//마지막 스위치까지 했는데 12안되면 실패 
	if (swtch == SWITCHES)
		return areAligned(clocks) ? 0 : INF;

	int ret = INF;
	for (int cnt = 0; cnt < 4; ++cnt) {
		// 최솟값 구하기
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
		//입력
		for (int i = 0; i < 16; i++) {
			cin >> clocks[i];
		}
		ans = solve(clocks, 0);
		//불가능 하면 -1, 아니면 결과값 출력
		if (ans == INF) cout << -1 << endl;
		else cout << ans << endl;
	}
}