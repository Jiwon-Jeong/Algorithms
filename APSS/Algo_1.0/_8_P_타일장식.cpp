#include <string>
#include <vector>

using namespace std;
long long solution(int N) {
	long long answer = 0;
	vector<long> temp;
	temp.push_back(0);
	temp.push_back(1);
	if (N == 1) {
		return 4;
	}
	else
		for (int i = 2; i < N + 1; i++) {
			temp.push_back(temp[i - 2] + temp[i - 1]);
		}
	answer = temp[N] * 4 + 2 * temp[N - 1];
	return answer;
}