#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer(heights.size());
	answer[0] = 0;
	for (int i = 1; i < heights.size(); i++) {
		answer[i] = 0;
		for (int j = i; j >= 0; j--) {
			if (heights[j] > heights[i]) {
				answer[i] = j + 1;
				break;
			}
		}
	}
	return answer;
}