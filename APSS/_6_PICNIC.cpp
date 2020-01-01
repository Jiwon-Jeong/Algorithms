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
	int firstFree = -1; //���� �ֵ� �� ���� ��ȣ ���� �л� ã�� 
	for (int i = 0; i < n; ++i) {
		if (!taken[i]) { //���� ¦ ������
			firstFree = i;
			break;
		}
	}

	//���� �� ������ ��� ¦ �����Ŵϱ� ����
	if (firstFree == -1) return 1;
	int ret = 0; //Parings ��

	//firstFree�� ¦ ���� ģ�� ã��
	for (int pairWith = firstFree + 1; pairWith < n; ++pairWith) {
		//���� ¦ ����, ģ����
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			//¦ �����ְ� ��������� �����ֵ�� ¦ ���� �� �ִ��� ã�ƺ�
			ret += countParings(taken);
			taken[firstFree] = taken[pairWith] = false;
		}
	}

	return ret;
}
