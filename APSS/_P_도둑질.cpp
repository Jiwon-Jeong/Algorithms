#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
	int answer = 0;
	int length = money.size();
	vector<int> dp(length - 1);
	vector<int> dp2(length);

	dp[0] = money[0];
	dp[1] = money[0];
	dp2[0] = 0;
	dp2[1] = money[1];
	for (int i = 2; i < length - 1; i++) {
		dp[i] = max(dp[i - 2] + money[i], dp[i - 1]);
	}
	for (int i = 2; i < length; i++) {
		dp2[i] = max(dp2[i - 2] + money[i], dp2[i - 1]);
	}

	return max(dp[length - 2], dp2[length - 1]);
}