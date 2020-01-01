#include<iostream>
using namespace std;

int n;
bool areFriends[10][10];
bool taken[10];
int countParings(bool[]);

void main() {
	int C, m;
	cin >> C;

	while (C-- > 0) {

		cin >> n;
		cin >> m;

		int i = 0, j = 0;
		while (m-- > 0) {
			cin >> i;
			cin >> j;
			areFriends[i][j] = true;
			areFriends[j][i] = true;
		}

		cout << countParings(taken) << endl;

	}

}


int countParings(bool taken[10]) {
	int firstFree = -1; //남은 애들 중 가장 번호 빠른 학생 찾기 
	for (int i = 0; i < n; ++i) {
		if (!taken[i]) { //아직 짝 없으면
			firstFree = i;
			break;
		}
	}

	//남은 애 없으면 모두 짝 지은거니까 종료
	if (firstFree == -1) return 1;
	int ret = 0; //Parings 수

	//firstFree랑 짝 지을 친구 찾기
	for (int pairWith = firstFree + 1; pairWith < n; ++pairWith) {
		//아직 짝 없고, 친구면
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			//짝 지어주고 재귀적으로 남은애들로 짝 지을 수 있는지 찾아봐
			ret += countParings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}

	return ret;
}
