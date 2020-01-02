#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int n1[5] = { 1,2,3,4,5 };
const int n2[8] = { 2,1,2,3,2,4,2,5 };
const int n3[10] = { 3,3,1,1,2,2,4,4,5,5 };

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> cnt(3, 0);
	int maxValue = 0;
	for (int i = 0; i < answers.size(); ++i) {
		if (answers[i] == n1[i % 5]) cnt[0]++;
		if (answers[i] == n2[i % 8]) cnt[1]++;
		if (answers[i] == n3[i % 10]) cnt[2]++;
	}
	maxValue = max(cnt[0], max(cnt[1], cnt[2]));
	for (int j = 0; j < 3; ++j) {
		if (cnt[j] == maxValue) answer.push_back(j + 1);
	}
	return answer;
}