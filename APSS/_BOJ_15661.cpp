#include <iostream>
#include <vector>
using namespace std;
int s[21][21];
int n;
int go(int index, vector<int>&start, vector<int>&link) {

	// ���� ã�� ���
	if (index == n) {
		// �� ã�� ���
		if (start.size() == 0) return -1;
		if (link.size() == 0) return -1;

		int ts = 0;
		int tl = 0;

		for (int i = 0; i < start.size(); i++) {
			for (int j = 0; j < start.size(); j++) {
				ts += s[start[i]][start[j]];
			}
		}
		for (int i = 0; i < link.size(); i++) {
			for (int j = 0; j < link.size(); j++) {
				tl += s[link[i]][link[j]];
			}
		}

		int diff = ts - tl;
		if (diff < 0) diff = -diff;
		return diff;
	}

	//���� ���
	int ans = -1;
	// index �� start�� �� ���
	start.push_back(index);
	int ts = go(index + 1, start, link);
	if (ans == -1 || (ts != -1 && ans > ts))
		ans = ts;
	start.pop_back(); //�ٽ� �������
	// index�� link�� �� ���
	link.push_back(index);
	int tl = go(index + 1, start, link);
	if (ans == -1 || (tl != -1 && ans > tl))
		ans = tl;
	link.pop_back();
	return ans;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> s[i][j];
		}
	}
	vector<int> start;
	vector<int> link;

	cout << go(0, start, link) << "\n";
	return 0;
}