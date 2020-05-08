#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> prices) {
	int len = prices.size();
	vector<int>answer(len, 0);
	for (int i = 0; i < len - 1; i++) {
		answer[i] += 1;
		for (int j = i + 1; j < len - 1; j++) {
			if (prices[i] > prices[j])
				break;
			answer[i] += 1;
		}
	}
	answer[len - 1] = 0;
	return answer;
}