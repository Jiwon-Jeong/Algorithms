#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = n - lost.size();
	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());

	// L==R
	for (int i = 0; i < lost.size(); i++) {
		for (int j = 0; j < reserve.size(); j++) {
			if (lost[i] == reserve[j]) {
				lost[i] = 0;
				reserve[j] = 0;
				answer++;
			}
		}
	}
	for (int i = 0; i < lost.size(); i++) {
		if (lost[i] == 0) lost.erase(lost.begin() + i);
	}
	for (int j = 0; j < reserve.size(); j++) {
		if (reserve[j] == 0) reserve.erase(reserve.begin() + j);
	}


	for (int i = 0; i < lost.size(); i++) {
		for (int j = 0; j < reserve.size(); j++) {
			if (lost[i] != 0 && reserve[j] != 0 && (lost[i] - 1) == reserve[j]) {
				lost[i] = 0;
				reserve[j] = 0;
				answer++;
				break;
			}
			else if (lost[i] != 0 && reserve[j] != 0 && (lost[i] + 1) == reserve[j]) {
				lost[i] = 0;
				reserve[j] = 0;
				answer++;
				break;
			}
		}
	}
	return answer;
}