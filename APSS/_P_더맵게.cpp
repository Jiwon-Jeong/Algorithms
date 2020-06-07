#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue< int, vector<int>, greater<int> > pq;
	for (int i : scoville)
		pq.push(i);
	while (pq.top() < K) {
		if (pq.size() <= 1) { return -1; }
		int n = pq.top(); pq.pop();
		n += (pq.top() * 2);  pq.pop();
		pq.push(n);
		answer++;
	}

	return answer;
}