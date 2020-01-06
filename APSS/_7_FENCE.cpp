#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> h; //height


/* solve: ������ �� �� �ε��� �־����� �ִ� ���� ���� */
int solve(int left, int right) { // index -> 6���� 0,6���� ����
	// B: ��Ÿ�� �ϳ� 
	if (left == right) return h[left];

	int mid = (left + right) / 2;
	// �ִ밡 �߰��� �������� ���� ��� - �����ؼ� ���
	int ret = max(solve(left, mid), solve(mid + 1, right));

	// �߰��� ������ �ִ� ��� - �߰����� �����ؼ� Ȯ���ϴ� ���
	int low = mid, high = mid + 1;
	int height = min(h[low], h[high]);
	ret = max(ret, height * 2);

	while (left<low || right>high) {

		// �� �߿� �� ���� ���ų� Ȯ�� ������ ������ 
		if (high < right && (low == left || h[low - 1] < h[high + 1])) { //���������� Ȯ��
			++high;
			height = min(height, h[high]);
		}
		else { // �������� Ȯ��
			--low;
			height = min(height, h[low]);
		}

		ret = max(height * (high - low+1), ret);
	}

	return ret;

}

void main() {
	int C, n, tmp;
	cin >> C;

	while (C--) {
		cin >> n;
		h.resize(n); // ������ ���� ���� ���༭ ũ�� �Ҵ�����
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			h[i] = tmp;
		}

		cout << solve(0, n - 1) << endl;
	}

}