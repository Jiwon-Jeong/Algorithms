#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> h; //height


/* solve: 판자의 양 끝 인덱스 주어지면 최대 넓이 리턴 */
int solve(int left, int right) { // index -> 6개면 0,6으로 들어옴
	// B: 울타리 하나 
	if (left == right) return h[left];

	int mid = (left + right) / 2;
	// 최대가 중간에 걸쳐지지 않은 경우 - 분할해서 계산
	int ret = max(solve(left, mid), solve(mid + 1, right));

	// 중간에 걸쳐져 있는 경우 - 중간부터 시작해서 확장하는 방법
	int low = mid, high = mid + 1;
	int height = min(h[low], h[high]);
	ret = max(ret, height * 2);

	while (left<low || right>high) {

		// 둘 중에 더 높이 높거나 확장 가능한 쪽으로 
		if (high < right && (low == left || h[low - 1] < h[high + 1])) { //오른쪽으로 확장
			++high;
			height = min(height, h[high]);
		}
		else { // 왼쪽으로 확장
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
		h.resize(n); // 위에서 벡터 선언만 해줘서 크기 할당해줌
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			h[i] = tmp;
		}

		cout << solve(0, n - 1) << endl;
	}

}