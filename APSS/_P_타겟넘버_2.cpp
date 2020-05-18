#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> numbers, int target) {
	int answer = 0;
	queue<int> q;
	q.push(numbers[0]);
	q.push(-numbers[0]);
	for (int i = 1; i < numbers.size(); i++) {
		int l = q.size();
		while (l--) {
			int top = q.front();
			q.pop();
			q.push(top + numbers[i]);
			q.push(top - numbers[i]);
		}
	}

	while (!q.empty()) {
		if (q.front() == target)
			answer++;
		q.pop();
	}
	return answer;
}