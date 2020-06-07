#include <string>

#include <vector>

#include <queue>



using namespace std;



int solution(vector<int> scoville, int K) {

	priority_queue<int, vector<int>, greater<int>> PQ;
	int answer = 0;
	for (int i = 0; i < scoville.size(); i++) {
		PQ.push(scoville[i]);
	}

	int mix;
	int first, second;

	if (PQ.top() < K) {
		first = PQ.top();
		PQ.pop();
		second = PQ.top();
		PQ.pop();
		answer++;
		first = first + second * 2;
		while (PQ.top() < K || first < K) {
			first = first + PQ.top() * 2;
			PQ.pop();
			answer++;
		}
	}
	return answer;

}
