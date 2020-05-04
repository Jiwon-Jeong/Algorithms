#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	int a, b, h;
	sort(citations.begin(), citations.end());
	for (int i = 0; i < citations.size(); i++) {
		a = citations[i];
		b = citations.size() - i;
		h = min(a, b);
		if (answer < h) {
			answer = h;
		}
	}
	return answer;
}